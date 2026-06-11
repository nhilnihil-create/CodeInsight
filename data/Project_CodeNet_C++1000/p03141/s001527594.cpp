#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define REP(i, a, b) for(ll i=(a); i<(b); i++)
#define PER(i, a, b) for(ll i=(a); i>=(b); i--)
#define rep(i, n) REP(i, 0, n)
#define per(i, n) PER(i, n, 0)
const ll INF = 1e18+18;
const ll MAX = 400005;
const ll MOD = 1000000007;
#define Yes(n) cout << ((n) ? "Yes" : "No") << endl;
#define YES(n) cout << ((n) ? "YES" : "NO") << endl;

/*long long fac[MAX], finv[MAX], inv[MAX];

void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}*/


int main(){
    ll N;
    cin>>N;
    vector<ll> A(N), B(N);
    vector<pair<ll, ll>> C(N);
    rep(i, N){
        cin>>A[i]>>B[i];
        C.at(i).first=A[i]+B[i];
      	C.at(i).second=i;
    }
    ll Sum=0;
  	sort(C.begin(), C.end());
  	reverse(C.begin(), C.end());
    rep(i, N){
        if(i%2){
          	Sum-=B[C.at(i).second];
        }
      	else{
          	Sum+=A[C.at(i).second];
        }
    }
    cout<<Sum<<endl;
}