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
#define drep(i,a,b) for(ll i=(a);i>=(b);--i)
#define SIZE(a) int((a).size())
#define out(a) cout<<(a)<<endl;
const int INF=INT_MAX;
const int MAX = 510000;
const ll MOD = 1000000007;
ll roundd(ll x,ll n){
  if(x>n){return x%n;}
  else if(x<0){return x%n+n;}
  else return x;
}

int main(){
  ll n,k;string s;cin>>n>>k>>s;
  ll cnt=0,ans=0;
  vp q;
  rep(i,0,n-1){
    cnt++;
    if(s[i]=='0'&&s[i+1]=='1'){q.push_back(make_pair(cnt,0));cnt=0;}
    if(s[i]=='1'&&s[i+1]=='0'){q.push_back(make_pair(cnt,1));cnt=0;}
  }
  if(s[n-1]=='0'){q.push_back(make_pair(cnt+1,0));}
  else q.push_back(make_pair(cnt+1,1));
  ll m=q.size();vll sum(m+1,0);
  rep(i,0,m){
    sum[i+1]=sum[i]+q[i].first;
  }
  rep(i,0,m){
    if(q[i].second){
      ans=max(ans,sum[min(m,i+2*k+1)]-sum[i]);
    }
    else ans=max(ans,sum[min(m,i+2*k)]-sum[i]);
  }
  cout<<ans<<endl;
}

