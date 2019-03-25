#pragma once

class CViewDlg: public SHostWnd
{
public:
	explicit CViewDlg(LPCTSTR pszResName);
	~CViewDlg();

	int OnCreate(LPCREATESTRUCT lpCreateStruct);
	BOOL OnInitDialog(HWND wndFocus, LPARAM lInitParam);
	void OnClose();
	void OnMaximize();
	void OnRestore();
	void OnMinimize();
	void OnSize(UINT nType, CSize size);
	void OnDropFiles(HDROP hDropInfo);
	void OnKeyDown(UINT nChar, UINT nRepCnt, UINT nFlags);
	LRESULT OnLoadSkin(UINT uMsg, WPARAM wParam, LPARAM lParam, BOOL &bHandled);
protected:
	//soui��Ϣ
	EVENT_MAP_BEGIN()
		EVENT_NAME_COMMAND(L"btn_close", OnClose)
		EVENT_NAME_COMMAND(L"btn_min", OnMinimize)
		EVENT_NAME_COMMAND(L"btn_max", OnMaximize)
		EVENT_NAME_COMMAND(L"btn_restore", OnRestore)
	EVENT_MAP_END()

	//HostWnd��ʵ������Ϣ����
	BEGIN_MSG_MAP_EX(CViewDlg)
		MSG_WM_CREATE(OnCreate)
		MSG_WM_INITDIALOG(OnInitDialog)
		MSG_WM_CLOSE(OnClose)
		MSG_WM_SIZE(OnSize)
		MSG_WM_DROPFILES(OnDropFiles)
		MSG_WM_KEYDOWN(OnKeyDown)
		MESSAGE_HANDLER(MSG_LOADSKIN, OnLoadSkin)
		CHAIN_MSG_MAP(SHostWnd)
		REFLECT_NOTIFICATIONS_EX()
	END_MSG_MAP()
private:
	BOOL			m_bLayoutInited;
};
