#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	int N;
	cin >> N;
	string S;
	cin >> S;
	int cntw = 0, cntb = 0;
	rep(i,S.size())
	{
		if (S[i] == '.') cntw++;
		else cntb++;
	}
	/*
	int cntlw = 0, cntrb = 0;
	rep(i,S.size())
	{
		if (S[i] == '.') cntlw++;
		else break;
	}
	for (int i = S.size()-1; i >= 0; --i)
	{
		if (S[i] == '#') cntrb++;
		else break;
	}
	*/
	//cout << cntw << " " << cntb << " " << cntlw << " " << cntrb << endl;
	int ans = cntw;
	int now = cntw;
	rep(i,S.size())
	{
		if (S[i] == '.')
		{
			now--;
		}
		else
		{
			now++;
		}
		ans = min(ans,now);
	}
	cout << ans << endl;
	return 0;
}