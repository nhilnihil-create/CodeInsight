#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep2(i, x, n) for(int i = x; i < n; i++)
#define elif else if
typedef long long ll;
typedef pair<ll, ll> P;
const ll MOD = 1e9+7;
const ll MOD2 = 998244353;
const ll INF = 1e15;

ll gcd(ll a, ll b){
    if(b == 0) return a;
    else return gcd(b, a%b);
}

int main(){
    ll N, A, B, K;
    cin >> N >> A >> B >> K;
    vector<P> vec;
    rep(i, N+1){
        if((A*i)%B == K % B && A*i <= K && K <= A*i + B*N){
            vec.push_back(P(i, (K-A*i)/B));
            break;
        }
    }
    if(vec.size() == 0) cout << 0 << endl, exit(0);
    ll s = vec[0].first;
    ll t = vec[0].second;
    ll g = gcd(A, B);
    ll stepA = B/g, stepB = A/g;
    while(s + stepA <= N && t - stepB >= 0){
        s += stepA;
        t -= stepB;
        vec.push_back(P(s, t));
    }
    ll n = N;
    ll inv[n+1];
    rep2(i, 1, n+1){
        inv[i] = 1;
        ll e[30];
        e[0] = i;
        rep2(j, 1, 30){
            e[j] = (e[j-1]*e[j-1]) % MOD2;
        }
        ll k = MOD2-2;
        int count = 0;
        while(k > 0){
            if(k % 2 == 1){
                inv[i] *= e[count];
                inv[i] %= MOD2;
            }
            k /= 2;
            count++;
        }
    }
    ll fac[N+1], perm[N+1];
    fac[0] = 1, perm[0] = 1;
    rep(i, N){
        fac[i+1] = (fac[i]*inv[i+1])%MOD2;
        perm[i+1] = (perm[i]*(N-i))%MOD2;
    }
    ll ans = 0;
    rep(i, vec.size()){
        ll s = vec[i].first, t = vec[i].second;
        ll tmp = 1;
        tmp *= perm[s], tmp %= MOD2;
        tmp *= fac[s], tmp %= MOD2;
        tmp *= perm[t], tmp %= MOD2;
        tmp *= fac[t], tmp %= MOD2;
        ans += tmp, ans %= MOD2;
    }
    cout << ans << endl;
}