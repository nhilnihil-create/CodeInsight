#include<bits/stdc++.h>
#include <math.h>
#include <map>
#include <unordered_map>
using namespace std;
#define rep(i,n) for(ll i=0;i<n;i++)
#define repl(i,l,r) for(ll i=(l);i<(r);i++)
#define per(i,n) for(ll i=n-1;i>=0;i--)
#define lper(i,r,l) for(ll i=r-1;i>=l;i--)
#define fi first
#define se second
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define CST(x) cout<<fixed<<setprecision(x)
#define pb(s) push_back(s)
#define ci(x) cin >>x
#define co(x) cout<<x<<endl
using ll=long long;
using vl=vector<ll>;
using vvl=vector<vector<ll>>;
using pl=pair<ll,ll>;
const ll MOD=1000000007;
const ll MOD9=998244353;
const int inf=1e9;
const ll INF=4e18;
const ll dy[4]={1,0,-1,0};
const ll dx[4]={0,-1,0,1};
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

long long fac(ll a) {
 long long ans=1;
 while(a>1){
 ans*=a;
 ans%=1000000007;
     a--;
    }
    return ans;
     }
int main() {
  ll N;
  cin >>N;
  
  vl vec(N+1);
  rep(i,N) {
cin >>vec.at(i);
  }
  vec.at(N)=INF;
  ll count=0;
  ll a=1;
  rep(i,N) {
    if(vec.at(i)==vec.at(i+1)) {
      a++;
    }
    else if(vec.at(i)!=vec.at(i+1)) {
      count +=floor((a)/2);
      a=1;
    }
    
  }
  
  cout<<count<<endl;
}
  
  
 