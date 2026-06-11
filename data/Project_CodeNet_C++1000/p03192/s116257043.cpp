#include <bits/stdc++.h>

using namespace std;

int main(void) 
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	string s;

	cin >> s;

	int res = 0;
	for(int i=0;i<s.length();i++)
	{
		if(s[i]=='2')
		{
			res++;
		}
	}

	cout << res << '\n';
	
	return 0;
}