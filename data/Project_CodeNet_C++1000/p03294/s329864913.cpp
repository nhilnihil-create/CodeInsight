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
    vi a(n);
    rep(i, n) cin >> a[i];
    ll sum = 0;
    rep(i, n) sum += a[i] - 1;
    cout << sum << "\n";
    // int mina = a[0];
    // int maxa = a[0];
    // rep(i, n)
    // {
    //     mina = min(mina, a[i]);
    //     maxa = max(maxa, a[i]);
    // }
    // int index = 0;
    // ll maxsum = 0;
    // rem(i, maxa, 1e5 + 1)
    // {
    //     ll sum = 0;
    //     for (const auto &e : a)
    //     {
    //         sum += (i % e);
    //     }
    //     cout << "i : " << i << "\n";
    //     cout << "sum : " << sum << "\n";
    //     if (sum > maxsum)
    //         index = i;
    //     maxsum = max(sum, maxsum);
    // }
    // cout << maxsum << "\n";
    // cout << index << "\n";
    return 0;
}