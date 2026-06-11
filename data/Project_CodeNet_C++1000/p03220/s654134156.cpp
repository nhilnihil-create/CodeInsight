#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()
#define all2(a, b) (a).begin(), (a).begin() + (b)
#define debug(vari) cerr << #vari << " = " << (vari) << endl;

int main()
{
    int n, t, a;
    cin >> n >> t >> a;
    vector<int> h(n);
    rep(i, n) cin >> h[i];

    int res = 1001001001;
    int ans;
    rep(i, n)
    {
        int ave_temp = 1000 * t - 6 * h[i];
        if (abs(ave_temp - 1000 * a) <= res)
        {
            res = abs(ave_temp - 1000 * a);
            ans = i;
        }
    }
    cout << ans + 1 << endl;

    return 0;
}
