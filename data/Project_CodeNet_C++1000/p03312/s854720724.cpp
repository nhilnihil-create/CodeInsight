#include <bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef long double ld;
const int inf=1e9+7;
const ll longinf=1LL<<60;
#define REP(i,m,n) for(int i=(int)(m) ; i < (int) (n) ; ++i )
#define rep(i,n) REP(i,0,n)
#define F first
#define S second
 
const int mx=200010;
const ll mod=1e9+7;



int main(){
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n){ cin>>a[i]; }
  rep(i,n-1){ a[i+1] += a[i]; }
  ll ans=longinf;

  for(int i=0; i<n-2; i++){
    vector<ll> v[4];
    if(i==0){ continue; }
    int j = lower_bound(a.begin(),a.end(),a[i]/2)-a.begin();
    int k = lower_bound(a.begin(),a.end(),(a[i]+a[n-1])/2)-a.begin();
    if(j<i){
      v[0].push_back(a[j]); v[0].push_back(a[i]-a[j]);
      v[1].push_back(a[j]); v[1].push_back(a[i]-a[j]);
    }
    if(j>0){
      v[2].push_back(a[j-1]); v[2].push_back(a[i]-a[j-1]);
      v[3].push_back(a[j-1]); v[3].push_back(a[i]-a[j-1]);
    }
    if(n-1!=k){
      v[0].push_back(a[k]-a[i]); v[0].push_back(a[n-1]-a[k]);
      v[2].push_back(a[k]-a[i]); v[2].push_back(a[n-1]-a[k]);
    }
    if(k-1>i){
      k--;
      v[3].push_back(a[k]-a[i]); v[3].push_back(a[n-1]-a[k]);
      v[1].push_back(a[k]-a[i]); v[1].push_back(a[n-1]-a[k]);
    }
    rep(p,4){
      sort(v[p].begin(),v[p].end());
      if((int)v[p].size()==4){ ans=min(ans,v[p][3]-v[p][0]); }
    }
  }
  cout<<ans<<endl;
  return 0;
}
  
