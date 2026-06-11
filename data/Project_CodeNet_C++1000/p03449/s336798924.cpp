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
    int n;
    cin >> n;
    vi a(n), b(n);
    rep(i, n) cin >> a[i];
    rep(i, n) cin >> b[i];

    int suma = 0, sumb = 0;
    rep(i, n) suma += a[i];
    rep(i, n) sumb += b[i];

    int sumA = 0;
    int ans = 0;
    rep(i, n)
    {
        ans = max(ans, a[i] + sumA + sumb);
        sumA += a[i];
        sumb -= b[i];
    }

    cout << ans << "\n";

    return 0;
}