#include <bits/stdc++.h>
using namespace std;
typedef long long  ll;
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define RFOR(i,a,n) for(ll i=(ll)n-1;i >= (ll)a;i--)
#define rep(i,n) FOR(i,0,n)
#define rrep(i,n) RFOR(i,0,n)
#define ALL(v) v.begin(), v.end()
#define bra(first,second) '(' << first << ',' << second << ')'
ll MOD = 1000000007;
//ll INF = 21474836470000000;
ll INF = 100100100100100100;
long double EPS = 1e-11;
long double PI = 3.141592653589793238;
template<typename T>
void remove(std::vector<T>& vector, unsigned int index){
    vector.erase(vector.begin() + index);
}

using Graph = vector<vector<ll>>;

int main(){
    ll N,K;
    cin >> N >> K;
    vector<ll> A(N),sum(N+1),B;
    rep(i,N){
        cin >> A[i];
        sum[i+1] = sum[i] + A[i];
    }
    rep(i,N) FOR(j,i+1,N+1){
        B.push_back(sum[j] - sum[i]);
    }
    ll ans = 0;
    rrep(k,45){
        ll cnt = 0;
        ll x = ans + (ll)pow(2,k);
        rep(i,B.size()){
            ll y = x & B[i];
            if(y == x) cnt++;
        }
        if(cnt >= K){
            ans += (ll)pow(2,k);
        }
    }
    cout << ans << endl;
}
