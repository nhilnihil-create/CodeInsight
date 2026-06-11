#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
string s[105],t[105];

int main()
{
	int N,M;
	cin >> N;
	rep(i,N)
	{
		cin >> s[i];
	}
	cin >> M;
	rep(i,M)
	{
		cin >> t[i];
	}
	int ans = 0;
	rep(i,N)
	{
		int res = 0;
		string temp = s[i];
		//cout << temp << endl;
		rep(j,N)
		{
			if (s[j] == temp) res++;
		}
		rep(j,M)
		{
			if (t[j] == temp) res--;
		}
		//cout << res << endl;
		ans = max(ans,res);
	}
	cout << ans << endl;
	return 0;
}