#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
#define M 1000000007
#define all(a) (a).begin(),(a).end()
#define rep(i,n) reps(i,0,n)
#define reps(i,m,n) for(int i=(m);i<(n);i++)
vector<ll> b;
vector<ll> xo(ll x){
  vector<ll> ret;
  int cnt=61;
  while(cnt>0){
    ret.push_back(x%2);
    x/=2;
    cnt--;
  }
  return ret;
}
int main(){
  ll n,k;cin>>n>>k;
  vector<ll> a(n);
  rep(i,n)cin>>a[i];
  rep(i,n){
    ll c=0LL;
    reps(j,i,n){
      c+=a[j];
      b.push_back(c);
    }
  }
  n=n*(n+1)/2;
  vector<vector<ll>> v(n);
  rep(i,n){
    v[i]=xo(b[i]);
  }
  vector<bool> m(n,false);
  ll p=1LL<<60,ans=0LL;
  for(int i=60;i>=0;i--){
    ll t=k;
    rep(j,n){
      if(!m[j]&&v[j][i]==1)t--;
    }
    if(t<=0){
      rep(j,n)if(v[j][i]==0)m[j]=true;
      ans+=p;
    }
    p/=2;
  }
  cout<<ans<<endl;
}