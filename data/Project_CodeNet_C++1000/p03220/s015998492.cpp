#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rem(i, m, n) for (int i = m; i < (n); i++)
#define eps (1e-7)
#define inf (1e9)
#define pi (acos(-1))
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int n, a;
    double t;
    cin >> n >> t >> a;
    vi h(n);
    rep(i, n) cin >> h[i];
    int ans = 1;
    double amin = abs(a - (t - 0.006 * h[0]));
    rem(i, 1, n)
    {

        double _amin = abs(a - (t - 0.006 * h[i]));
        //cout << _amin << "\n";
        if (_amin < amin)
        {
            amin = _amin;
            ans = i + 1;
        }
    }

    cout << ans << "\n";

    return 0;
}