#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll N;
    cin >> N;
    vector<ll> X(N);
    rep(i, N){
        cin >> X[i];
    }
    vector<ll> X_(X);
    sort(X.begin(), X.end());

    rep(i, N){
        ll ans = 0;
        if (X_[i] <= X[N/2-1]){
            ans = X[N/2];
        }else{
            ans = X[N/2-1];
        }
        cout << ans << endl;
    }

    return 0;
}
