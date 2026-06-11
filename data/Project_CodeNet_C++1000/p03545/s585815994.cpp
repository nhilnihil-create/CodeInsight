#include<bits/stdc++.h>
using namespace std;

string s, ans;

void solve(int i, string x, int sum)
{
	if (i == 4) 
	{
		if (sum == 7) ans = x;
		return;
	}
	solve(i+1, x+"+"+s[i], sum+s[i]-48);
	solve(i+1, x+"-"+s[i], sum-s[i]+48);
}

int main()
{
	cin >> s;
	solve(1, "", s[0]-48);
	cout << s[0] << ans << "=7" << endl;
}

