#include<bits/stdc++.h>
using namespace std;
#define ll long long
typedef pair<ll,ll> P;
typedef pair<ll,P> PP;
const ll MOD = 1e9+7;

int main(){
  int h,w,n;
  vector<P> p;
  cin>>h>>w>>n;
  for(int i=0;i<n;i++){
    int x,y;
    cin>>x>>y;
    if(y>x)continue;
    p.push_back(P(x,y));
  }
  sort(p.begin(),p.end());
  int x=1,y=1;
  ll ans=h;
  for(int i=0;i<p.size();i++){
    if(p[i].first-x<p[i].second-y)continue;
    if(p[i].first-x==p[i].second-y){
	 x=p[i].first,y=p[i].second-1;
    }else{
	 ans=min(ans,p[i].first-1);
	 break;
    }
  }
  
  cout<<ans<<endl;
  return 0;
}
