#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define mod 1000000007
//#define mod 998244353
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
/*void chmax(P &a,P b) {
  if (a.ft<b.ft) a.sc=max(a.ft,b.sc), a.ft=b.ft;
  else a.sc=max(a.sc,b.ft);
}*/

const ll INF=1e18;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    ll n,m;
    cin>>n>>m;
    ll ans;
    V<ll> d;
    for(ll i=1;i*i<=m;i++){
        if(m%i==0){
            d.push_back(i);
            if(i!=m/i){
                d.push_back(m/i);
            }
        }
    }
    sort(all(d));
    ll cnt=lb(all(d),n)-d.begin();
    ans=m/d[cnt];
    cout<<ans<<endl;
}