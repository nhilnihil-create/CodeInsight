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
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
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

bool my_compare(pair<ll,ll> a,pair<ll,ll> b){
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
    rrep(i,n) x*=i;
    return x;
}

ll gcd(ll a,ll b) { return b ? gcd(b, a%b) : a; }

ll func(ll a,ll b,ll& ans_x,ll& ans_y){
    if(b == 0){
        ans_x = 1;
        ans_y = 0;
        return a;
    }else{
        ll ret = func(b,(a%b),ans_y,ans_x);
        ans_y -= (a/b)*ans_x;
        return ret;
    }
}

ll lcm(ll a,ll b){
   return a/gcd(a,b)*b;
}
const ll MAX = 5100000;
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
pair<pair<ll,ll>,ll> p[100010];

ll dp[50010];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll n,ans=0;
    cin>>n;
    pair<ll,ll> red[n],blue[n];
    rep(i,n) cin>>red[i].first>>red[i].second;
    rep(i,n) cin>>blue[i].first>>blue[i].second;
    sort(red,red+n);
    sort(blue,blue+n);
    
    rep(i,n){
        ll maxi=-INF,minit=INF;
        rep(j,n){
            if(blue[i].second>red[j].second && blue[i].first>red[j].first){
                if(maxi<red[j].second){
                    maxi=red[j].second; minit=j;
                }
            }
        }
        if(minit!=INF){
            blue[i].second=INF; red[minit].second=INF;
            blue[i].first=INF; red[minit].first=INF;
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
