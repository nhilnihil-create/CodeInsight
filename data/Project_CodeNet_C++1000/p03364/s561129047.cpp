#include<bits/stdc++.h>
#define rep(i,n,m) for(int i = (n); i <(m); i++)
#define rrep(i,n,m) for(int i = (n) - 1; i >=(m); i--)
using namespace std;
using ll = long long;

int main()
{
    int n;
    cin >> n;
    string s[n];
    rep(i, 0, n) cin >> s[i];

    int ans = 0;
    rep(k, 0, n)
    {
        bool is_ok = true;
        rep(i, 0, n)
        {
            rep(j, 0, n)
            if (i < j)
            {
                int x1, y1, x2, y2;
                y1 = (k + i) % n; 
                x1 = j;
                y2 = (k + j) % n;
                x2 = i;

                is_ok &= s[x1][y1] == s[x2][y2];
            }
            if (!is_ok) break;
        }

        if (is_ok)
            ans += n;
        // cout << k << ' ' << is_ok << ' ' << ans << endl;
    }
    cout << ans << endl;
    return 0;
}