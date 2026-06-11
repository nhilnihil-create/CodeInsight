#include <bits/stdc++.h>
using namespace std;\
typedef long long ll;
typedef pair<ll,ll> P;
int main() {
  int n,m,a,b; cin>>n>>m;
  ll s=0;
  vector<P> v; for(int i=0;i<n;i++) cin>>a>>b,v.push_back(P(a,b));
  sort(v.begin(),v.end());
  for(P p:v){
    if(m>p.second) m-=p.second,s+=p.first*p.second;
    else{
      s+=p.first*m;
      break;
    }
  }
  cout<<s;
}