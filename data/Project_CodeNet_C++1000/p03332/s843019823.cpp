#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#include <map>
#include <stdio.h>
#include <cstring> //memset(dp,0,sizeof(dp))
#include <functional> //operator[]
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define fi first
#define se second
#define pb push_back
#define ALL(a) (a).begin(),(a).end()
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
typedef pair<ll,ll> Pll;

const int MAX = 1001001;
const ll MOD = 998244353;
ll fac[MAX],finv[MAX],inv[MAX];
void COMinit(){
    fac[0]=fac[1]=1;
    finv[0]=finv[1]=1;
    inv[1]=1;
    for(int i=2;i<MAX;i++){
        fac[i]=fac[i-1]*i % MOD;
        inv[i]=MOD-inv[MOD%i]*(MOD/i) % MOD;
        finv[i]=finv[i-1]*inv[i] % MOD;
    }
}
ll COM(int n,int k){
    if(n<k) return 0;
    if(n<0 || k<0) return 0;
    return fac[n]*(finv[k]*finv[n-k] % MOD) % MOD;
}
signed main(){
    COMinit();
    ll n,a,b,k;
    cin >> n >> a >> b >> k;
    ll ans=0;
    rep(p,n+1){
        if((k-a*p)%b==0){
            ll q=(k-a*p)/b;
            ans+=(COM(n,p)*COM(n,q))%MOD;
            ans%=MOD;
        }
    }
    cout << ans << endl;
}
