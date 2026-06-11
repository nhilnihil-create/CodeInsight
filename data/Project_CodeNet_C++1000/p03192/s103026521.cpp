#include <bits/stdc++.h>

using namespace std;

string s;
int ans;

int main(void)
{
	ios::sync_with_stdio(false);
	cin >> s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='2')
		{
			ans++;
		}
	}
	cout << ans << endl;
	return 0;
}