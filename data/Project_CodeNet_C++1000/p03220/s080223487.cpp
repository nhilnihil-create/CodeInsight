#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;
const int MOD = 1e9 + 7;

int main()
{
    int n, t, a;
    cin >> n >> t >> a;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    int ans;
    int res = 1001001001;

    rep(i, n)
    {
        if (abs(a*1000 - (t * 1000 - h[i] * 6)) < res)
        {
            res = abs(a*1000 - (t * 1000 - h[i] * 6));
            ans = i + 1;
        }
    }

    cout << ans << endl;
    return (0);
}
