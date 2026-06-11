#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <iomanip>
#include <utility>
#include <tuple>
#include <functional>
#include <bitset>
#include <cassert>
#include <complex>
#include <stdio.h>
#include <time.h>
#include <numeric>
#include <unordered_map>
#include <unordered_set>
# define ll int64_t
# define str string
# define rep(i,n) for(ll i=0;i<n;i++)
# define rrep(i,n) for(ll i=1;i<=n;i++)
# define ALL(x) (x).begin(), (x).end()
# define SZ(x) ((int)(x).size())
# define pb push_back
# define mod 1000000007
# define PI 3.141592653589793
# define vec vector
#define dump(x) cerr<<#x<<"="<<x<<endl
using namespace std;



#define INF 2000000000
#define MAX_V 10



bool compare_by_b(pair<string,ll> a,pair<string,ll> b){
    if(a.second != b.second) return a.second<b.second;
    else return a.first<b.first;
}

bool my_compare(pair<string,ll> a,pair<string,ll> b){
    if(a.first != b.first) return a.first<b.first;
    if(a.second != b.second) return a.second>b.second;
    else return true;
}

ll modpow(ll a,ll n,ll mod1) {
    ll res=1;
    while(n>0){
        if(n&1) res=res*a%mod1;
        a = a*a%mod1;
        n >>= 1;
    }
    return res;
}

ll factorial(ll n){
    ll x=1;
    rrep(i,n) (x*=i)%=mod;
    return x;
}

ll gcd(ll a,ll b){
   if (a%b == 0) return(b);
   else return(gcd(b,a%b));
}

ll lcm(ll a,ll b){
   return a/gcd(a,b)*b;
}
const ll MAX = 510000;
const ll MOD = 1000000007;
 
ll fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (ll i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

// 二項係数計算
ll COM(ll n, ll k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

using graph = vector<vector<ll>>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    //最初を値、2番目をカウント値
   
    ll n;
    cin>>n;
     
    map<ll,ll> odd,even;
    rep(i,n){
        if((i+1)%2==0){
            ll a;
            cin>>a;
            odd[a]++;
        }else{
            ll a;
            cin>>a;
            even[a]++;
        }
    }
    priority_queue<pair<ll,ll>> q1,q2;
    for(auto i:odd) q1.emplace(i.second,i.first);
    for(auto i:even) q2.emplace(i.second,i.first);
    
    vec<pair<ll,ll>> p1(2,pair<ll,ll>(n/2 + 1,0)),p2(2,pair<ll,ll>(n/2 + 1,0));
    rep(i,2){
        if(!q1.empty()){
            pair<ll, ll> p;
            p = q1.top();
            q1.pop();
            p1[i] = p;
            
        }
        if(!q2.empty()){
            pair<ll,ll> q;
            q = q2.top();
            q2.pop();
            p2[i] = q;
            
        }
    }
    ll ans=n;
    rep(i,2){
        rep(j,2){
            if(p1[i].second == p2[j].second) continue;
            ll res = n;
            if(p1[i].second!=0) res -= p1[i].first;
            if(p2[j].second!=0) res -= p2[j].first;
            ans = min(ans,res);
        }
    }
    cout<<ans<<endl;
    return 0;
}
