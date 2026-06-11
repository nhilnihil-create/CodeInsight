#include <bits/stdc++.h>
const int INF = 1e9, MOD = 1e9 + 7;
const long long LINF = 1e18;
using namespace std;
#define int long long
//template

//main
signed main()
{
    int H, W, N;
    cin >> H >> W >> N;
    int sy, sx;
    cin >> sy >> sx;
    string s, t;
    cin >> s >> t;
    int l = 1, r = W;
    int out = 0;
    for (int i = N - 1; i >= 0; i--)
    {
        if (t[i] == 'R')
            l--;
        if (t[i] == 'L')
            r++;
        l = max(1LL, l);
        r = min(W, r);
        if (s[i] == 'R')
            r--;
        if (s[i] == 'L')
            l++;

        if (r < l)
            out++;
    }
    if (sx < l || sx > r)
        out++;
    l = 1;
    r = H;
    for (int i = N - 1; i >= 0; i--)
    {
        if (t[i] == 'D')
            l--;
        if (t[i] == 'U')
            r++;
        l = max(1LL, l);
        r = min(H, r);
        if (s[i] == 'D')
            r--;
        if (s[i] == 'U')
            l++;

        if (r < l)
            out++;
    }
    if (sy < l || sy > r)
        out++;
    if (out)
        cout << "NO" << endl;
    else
        cout << "YES" << endl;
}
