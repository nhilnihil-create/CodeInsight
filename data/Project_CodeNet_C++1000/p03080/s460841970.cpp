#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    int n;
    cin >> n >> s;
    int c0 = 0, c1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'R') c0++;
        else c1++;
    }
    if (c0 > c1) cout << "Yes";
    else cout << "No";
}
