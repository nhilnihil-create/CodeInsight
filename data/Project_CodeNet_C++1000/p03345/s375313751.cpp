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

    ll a, b, c, k;
    cin >> a >> b >> c >> k;

    ll ans;
    if (k % 2 == 0)
    {
        ans = a - b;
    }
    else
    {
        ans = b - a;
    }

    if (ans > 1e18)
        cout << "Unfair"
             << "\n";
    else
        cout << ans << "\n";

    return 0;
}