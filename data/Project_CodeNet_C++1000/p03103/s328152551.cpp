#include "bits/stdc++.h"
#include "math.h"
 
using namespace std;
typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<bool> vb;
typedef vector<vb> vvb;
typedef vector<int> vin;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define rep(i,a,b) for(ll i=(a);i<(b);++i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const int MOD = 1000000007;

int main(){
  ll n,m,count=0,ans=0;cin>>n>>m;
  vp d(n);
  rep(i,0,n){
    cin>>d[i].first>>d[i].second;
  }
  sort(d.begin(),d.end());
  rep(i,0,n){
    if(count>=m){break;}
    ans+=d[i].first*min(m-count,d[i].second);
    count+=d[i].second;
  }
  cout<<ans<<endl;
}