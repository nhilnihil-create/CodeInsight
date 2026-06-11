#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main()
{
	string s;
	cin >> s;

	string elimx = "";
	rep(i,s.size())
	{
		if (s[i] != 'x') elimx += s[i];
	}
	rep(i,elimx.size()/2)
	{
		if (elimx[i] != elimx[elimx.size()-1-i])
		{
			cout << "-1" << endl;
			return 0;
		}
	}
	int l = 0, r = s.size()-1, ans = 0;
	while(l < r)
	{
		if (s[l] == 'x' && s[r] != 'x')
		{
			ans++;
			l++;
		}
		else if (s[l] != 'x' && s[r] == 'x')
		{
			ans++;
			r--;
		}
		else
		{
			l++; r--;
		}
	}
	cout << ans << endl;
	return 0;
}