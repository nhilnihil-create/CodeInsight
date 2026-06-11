#include <bits/stdc++.h>
using namespace std;
string s;
int ans = INT_MAX;
int main()
{
    ios::sync_with_stdio(false);
	cin >> s;
	for (int i = 1; i < s.length(); ++i)
    {
        if (s[i] != s[i - 1])
        {
            ans = min(ans, max(i, (int)(s.length() - i)));
        }
    }
    cout << min(ans, (int)s.length()) << endl;
	return 0;
}