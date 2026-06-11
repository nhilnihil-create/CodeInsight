#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,n) for(int i=0; i<(int)(n); ++i)
#define REP(i,m,n) for(ll i=(ll)(m); i<(ll)(n); ++i)
#define F first
#define S second
const double PI=acos(-1);
//fixed<<setprecision(11)<<

int main(){
  int n,m;
  cin>>n>>m;
  int la=0,ra=n;
  vector<int> l(m),r(m);
  rep(i,m){
    cin>>l[i]>>r[i];
    la=max(la,l[i]);
    ra=min(ra,r[i]);
  }
  int ans=ra-la+1;
  if (ans<=0)ans=0;
  cout<<ans<<endl;
return 0;
}