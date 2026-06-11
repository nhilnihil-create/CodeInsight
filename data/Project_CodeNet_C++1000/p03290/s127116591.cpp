#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define rep(i, n) for (int i = 0; i < n; i++)

int main()
{
  ll d,g,t,sum=1e9;
  cin >>d>>g;
  vector<P> p(d);
  rep(i,d){
    cin >>p[i].first>>p[i].second;
  }
  rep(i,1<<d){
    ll ans=0,num=0;
    rep(j,d){
      if(i&1<<j){
        ans+= 100*(j+1)*p[j].first+p[j].second;
        num+=p[j].first;
      }else{
        t=j;
      }
    }
    for(int j=0;j<p[t].first&&ans<g;j++) ans+=100*(t+1),num++;
    if(ans>=g) sum=min(sum,num);
  }
  cout <<sum<<endl;
}
