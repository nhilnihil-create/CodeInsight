#include <bits/stdc++.h>
using namespace std;
#define mp make_pair
using pi=pair<int,int>;
#define int long
signed main(){
  int N,C,r=0;
  cin>>N>>C;
  vector<vector<pi>> v(C);
  int s,t,c;
  for(int i=0;i<N;++i){
    cin>>s>>t>>c;
    v[c-1].emplace_back(s,t);
  }
  for(int i=0;i<C;++i){
    if(v[i].empty())continue;
    sort(v[i].begin(),v[i].end());
    vector<pi> vv;
    vv.push_back(v[i][0]);
    int szvv=1;
    for(int j=1;j<v[i].size();++j){
      if(v[i][j].first==v[i][j-1].second)vv[szvv-1].second=v[i][j].second;
      else vv.push_back(v[i][j]),++szvv;
    }
    v[i]=vv;
  }
  
  vector<int> T(100010,0);
  for(auto& vv:v)for(auto& p:vv)++T[p.first-1],--T[p.second];
  for(int i=1;i<100010;++i)r=max(r,T[i]+=T[i-1]);
  cout<<max(r,T[0]);
}