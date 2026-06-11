#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, a, b) for (int i = (a); i < (b); ++i)
#define all(a) (a).begin(), (a).end()

int main()
{
    ll n;
    cin >> n;
    vector<ll> v(5);
    rep(i, 5) cin >> v[i];

    sort(all(v));

    cout << 5 + (n + v[0] - 1) / v[0] - 1 << endl;
    return 0;
}
