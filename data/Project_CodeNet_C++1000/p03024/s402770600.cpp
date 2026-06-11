#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int cnt = 0;
    string s;

    cin >> s;

    for(int i=0;i<s.length();i++)
    {
    	if(s[i]=='o')
    	{
    		cnt++;
    	}
    }

    if(cnt + (15 - s.length())>=8)
    {
    	cout << "YES" << '\n';
    }
    else
    {
    	cout << "NO" << '\n';
    }

    return 0;
}