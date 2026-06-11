#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

ll gcd(ll a, ll b){
    if (b == 0){
        return a;
    }
    return gcd(b, a % b);
}

int main()
{
    ll N, X;
    cin >> N >> X;
    vector<ll> x(N+1);
    rep(i, N){
        cin >> x[i];
    }
    x[N] = X;
    sort(x.begin(), x.end());
    vector<ll> x_diff(N);
    ll D = x[1] - x[0];
    rep(i, N){
        x_diff[i] = x[i+1] - x[i];
        D = gcd(D, x_diff[i]);
    }
    cout << D << endl;

    return 0;
}
