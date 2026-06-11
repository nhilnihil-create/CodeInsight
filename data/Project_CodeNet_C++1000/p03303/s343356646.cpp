#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int k;
    cin >> s >> k;
    for (int i = 0; i < s.size(); i += k)
    {
        cout << s[i];
    }
}
