#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)

int main()
{
    ll N, M;
    cin >> N >> M;
    vector<ll> X(M);
    rep(i, M){
        cin >> X[i];
    }

    if (N >= M){
        puts("0");
        return 0;
    }

    vector<pair<ll, ll>> X_diff(M-1);
    sort(X.begin(), X.end());
    rep(i, M-1){
        X_diff[i] = make_pair<ll, ll>(X[i+1] - X[i], ll(i));
    }
    sort(X_diff.begin(), X_diff.end(), greater<pair<ll, ll>>());
    vector<ll> indices(N-1);
    rep(i, N-1){
        indices[i] = X_diff[i].second;
    }
    sort(indices.begin(), indices.end());
    ll ans = 0;
    ll pre_i = 0;
    rep(i, N-1){
        ll end_i = indices[i];
        ans += X[end_i] - X[pre_i];
        pre_i = end_i+1;
    }
    ans += X[M-1] - X[pre_i];

    cout << ans << endl;
    

    return 0;
}
