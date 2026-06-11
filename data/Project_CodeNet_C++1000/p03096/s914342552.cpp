#include<bits/stdc++.h>
using namespace std;
#define REP(i,n) for(int i=0;i<(n);++i)
#define FOR(i,k,n) for(int i=(k);i<(n);++i)
typedef long long ll;

const ll MOD = 1000000007;

inline ll add(ll x, ll y) {return (x+y)%MOD;}
inline ll mul(ll x, ll y) {return (x*y)%MOD;}
inline ll sub(ll x, ll y) {
    ll res = x - y;
    if(res < 0) res += MOD;
    return res;
}

int main() {
    int N; cin >> N;
    vector<ll> C(N);
    REP(i,N) cin >> C[i];
    vector<ll> vec(200005,-1);
    vector<ll> dp(N,0);
    dp[0] = 1;
    vec[C[0]] = 0;
    FOR(i,1,N) {
        if(vec[C[i]]==i-1 || vec[C[i]]==-1) {
            dp[i] = dp[i-1];
            vec[C[i]] = i;
        }
        else {
            dp[i] = add(dp[i-1],dp[vec[C[i]]]);
            vec[C[i]] = i;
        }
    }
    cout << dp[N-1] << endl;
    return 0;
}