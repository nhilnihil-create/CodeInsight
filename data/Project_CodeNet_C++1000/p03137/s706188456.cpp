#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, srt, end) for (long long i = (srt); i < (long long)(end); i++)

int main(){
    ll N, M;
    cin >> N >> M;
    vector<ll> X(M), dx(M-1);
    rep(i, 0, M) cin >> X[i];
    sort(X.begin(), X.end());
    rep(i, 0, M-1) dx[i] = X[i+1] - X[i];
    sort(dx.begin(), dx.end());
    ll ans = 0;
    rep(i, 0, M-N) ans += dx[i];
    cout << ans << endl;
    return 0;
}