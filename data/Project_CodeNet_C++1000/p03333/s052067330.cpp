#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
#define fi first
#define se second
typedef pair<ll,ll> P;
using VP = vector<P>; using VVP = vector<VP>;
using VI = vector<ll>; using VVI = vector<VI>; using VVVI = vector<VVI>;
const int inf=1e9+7;
const ll INF=1LL<<61;
const ll mod=1e9+7;


int main(){
  int i,j;
  int n;
  cin>>n;
  ll l[n],r[n];
  for(i=0;i<n;i++) cin>>l[i]>>r[i];
  sort(l,l+n,greater<ll>());
  sort(r,r+n);
  ll ans=0;
  int p=0;
  ll tem=0;
  while(l[p]>=r[p]){
    ans+=2*(l[p]-r[p]);
    p++;
    if(p!=n) tem=max(tem,ans+max(0ll,max(2*l[p],-2*r[p])));
  }
  cout<<tem<<endl;
  
  return 0;
}
