#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define max3(a,b,c) max(max(a,b),c)
#define min3(a,b,c) min(min(a,b),c)
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//V,P(大文字)使用不可

const ll INF=1e18;

vector<ll> divisor(ll n){
    vector<ll> res;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            res.push_back(i);
            if(i!=n/i) res.push_back(n/i);
        }
    }
    return res;
}

signed main(){
    ll n;
    cin>>n;
    //vector<ll> a=divisor(n);
    ll ans=0;
    if(n>2) ans=n-1;
    for(ll i=2;i*i<=n;i++){
        if(n%i==0){
            if(i<=n/i-2) ans+=n/i-1;
            if(i!=n/i){
                ll t=n/i;
                if(t<=n/t-2) ans+=n/t-1;
            }
        }
    }
    cout<<ans<<endl;
}