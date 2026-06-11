#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    ll N, K; cin >> N >> K;

    vector<ll> X(N);
    for (ll i = 0; i < N; i++) {
        cin >> X[i];
    }

    ll c;
    c = lower_bound(ALL(X), 0) - X.begin();

    ll ans = INF;
    for (ll a = 1; a < K; a++) {
        if(c + a - 1 <= N-1 && c - K + a >= 0){
            ans = min(ans, min(X[c+a-1], -X[c-K+a]) + X[c+a-1] - X[c-K+a]);
        }
    }

    if(c-K >= 0){
        ans = min(ans, -X[c-K]);
    }
    if(c+K-1 <= N-1){
        ans = min(ans, X[c+K-1]);
    }
    printf("%lld\n", ans);

}
