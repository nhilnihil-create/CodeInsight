#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
constexpr int Inf = 1000000000;
constexpr ll INF= 1e18;
constexpr ll MOD = 1000000007;
const double PI = 3.1415926535897;
typedef pair<ll,ll> P;
 
template<typename T>
T Pow(T a,T b) {
    T ret = 1;
    for(int i = 0;i < b;i++) {
        ret *= a;
    }
    return ret;
}
 
ll mod(ll val) {
    ll res = val % MOD;
    if(res < 0) {
        res += MOD;
    }
    return res;
}
 
ll RepeatSquaring(ll N, ll P, ll M){
    if(P==0) return 1;
    if(P%2==0){
        ll t = RepeatSquaring(N, P/2, M);
        return t*t % M;
    }
    return N * RepeatSquaring(N, P-1, M) % M;
}

int main() {
    int N;
    cin >> N;
    vector<int> vec(N);
    for(int i = 0;i < N;i++) {
        cin >> vec.at(i);
    }
    vector<int> cnt(200020,-1);
    ll dp[200020];
    dp[0] = 1;
    for(int i = 0;i < N;i++) {
        dp[i + 1] = dp[i];
        if(cnt.at(vec.at(i)) >= 0 && cnt.at(vec.at(i)) < i - 1) {
            dp[i + 1] = (dp[i + 1] + dp[cnt.at(vec.at(i)) + 1]) % MOD;
        }
        cnt.at(vec.at(i)) = i;
    }
    cout << dp[N] << endl;
}