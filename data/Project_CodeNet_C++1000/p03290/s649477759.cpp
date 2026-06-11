#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); i++) 
#define all(v) begin(v),end(v)
using ll = long long;

int main() {
  int d,g;cin>>d>>g;
  vector<int> p(d),c(d);
  rep(i,d)cin>>p[i]>>c[i];
  int ans=1e9;
  rep(bit,1<<d){
    int cnt=0,sum=0,a=-1;
    rep(i,d){
      if(bit&(1<<i)){
        cnt+=p[i];
        sum+=100*(i+1)*p[i]+c[i];
      }
      else a=i;
    }
    if(sum<g){
      int sum1=100*(a+1);
      int x=(g-sum+sum1-1)/sum1;
      if(x>=p[a])continue;
      cnt+=x;
    }
    ans=min(ans,cnt);
  }
  cout<<ans<<endl;
}