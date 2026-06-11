#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    ll N, A, B, K;
    cin >> N >> A >> B >> K;

    vector<ll> fact(N+1);
    fact[0] = 1; fact[1] = 1;
    for (int i = 2; i < N+1; i++) {
        fact[i] = fact[i-1] * i % MOD;
    }   

    vector<ll> inv(N+1); inv[1] = 1;
    for (int i = 2; i < N+1; i++) {
        inv[i] = MOD - (MOD / i) * inv[MOD % i] % MOD;
    }   
    vector<ll> invfact(N+1);
    invfact[0] = 1; invfact[1] = 1;
    for (int i = 2; i < N+1; i++) {
        invfact[i] = invfact[i-1] * inv[i] % MOD;
    }   

    ll ans = 0;
    ll tmp;
    for (ll i = 0; i < N+1; i++) {
        if(K - i * A >= 0 && (K - i * A) % B == 0 && (K - i * A) / B <= N){
            tmp = fact[N] * fact[N] % MOD;
            tmp = tmp * invfact[i] % MOD;
            tmp = tmp * invfact[N-i] % MOD;
            tmp = tmp * invfact[(K - i * A) / B] % MOD;
            tmp = tmp * invfact[N - (K - i * A) / B] % MOD;
            ans = (ans + tmp) % MOD;
        }


    }

    printf("%lld\n", ans);

}
