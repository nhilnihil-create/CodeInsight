#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<int, int> PII;
typedef pair<ll, ll> PLL;
#define INF 1000000000
#define MOD 998244353
#define EPS 0.00000001


ll power(ll a, ll e){
    if(e==0) return 1;
    if(e%2==0){
        ll r = power(a, e/2);
        return r * r % MOD;
    } else {
        ll r = power(a, e/2);
        return r * r % MOD * a % MOD;
    }
}

ll Inv(ll a){
    return power(a, MOD-2);
}

ll Fact(ll a){
    ll r = 1;
    for(int i=2; i<=a; i++)
        r = r * i % MOD;
    return r;
}


ll Combi(ll a, ll b){
    return Fact(a) % MOD * Inv(Fact(b)) % MOD * Inv(Fact(a-b)) % MOD;
}

ll N, A, B, K;
vector<ll> F;
ll solve(ll a, ll b){
    return F[a] % MOD * Inv(F[b]) % MOD * Inv(F[a-b]) % MOD;
}


int main(){
    cin >> N >> A >> B >> K;
    F.resize(N+1);
    ll ans = 0;
    F[0] = 1;
    for(int i=1; i<=N; i++){
        F[i] = F[i-1] * i % MOD;
    }
    
    for(ll i=0; i<=N; i++){
        ll j = (K - i * A)/B;
        if(j>=0 && j<=N && i*A + j*B == K){
            ans += solve(N, i) * solve(N, j) % MOD;
            ans %= MOD;
        }
    }

    cout << ans << endl;
    return 0;
}
