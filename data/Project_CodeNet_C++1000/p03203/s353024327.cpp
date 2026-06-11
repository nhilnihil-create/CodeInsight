#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<ll> kabe[200005];
int main(){
  ll h,w,n;
  cin>>h>>w>>n;
  ll ans=h;
  for(int i=0;i<n;i++){
    ll x,y;
    cin>>x>>y;
    kabe[x].push_back(y);
  }
  for(int i=1;i<=h;i++) {
    kabe[i].push_back(17441744);
    sort(kabe[i].begin(),kabe[i].end());
  }
  ll c=0;
  for(int i=1;i<=h;i++) {
    if(i-c-1>=kabe[i][0]){
      cout<<i-1<<endl;
      return 0;
    }
    else{
      ll ky=*(lower_bound(kabe[i].begin(),kabe[i].end(),i-c));
      if(ky==i-c) c++;
    }
  }
  cout<<ans<<endl;
}
