#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define agewari(a, b) ((ll)a + ((ll)b - 1)) / b
const int MOD = 1000000007;
const long long INF = 1LL << 60;
using Graph = vector<vector<ll>>;

int main()
{
    ll n, m;
    cin >> n >> m;
    vector<ll> X(m);
    rep(i, m) cin >> X[i];

    if (n >= m)
    {
        cout << 0 << endl;
        return 0;
    }

    sort(X.begin(), X.end());
    ll moto = X[m - 1] - X[0];
    vector<ll> sa(m - 1);
    rep(i, m - 1) sa[i] = X[i + 1] - X[i];
    ll hiku = 0;
    sort(sa.begin(), sa.end(), greater<ll>());
    rep(i, n - 1) hiku += sa[i];

    cout << moto - hiku << endl;
}