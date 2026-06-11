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

    int n, k;
    cin >> n >> k;
    vi h(n);
    rep(i, n) cin >> h[i];
    sort(h.begin(), h.end());

    int ans = inf;
    rep(i, n - k + 1)
    {
        //cout << h[i] << ", " << h[i + k - 1] << "\n";
        ans = min(ans, h[i + k - 1] - h[i]);
    }
    cout << ans << "\n";
    return 0;
}