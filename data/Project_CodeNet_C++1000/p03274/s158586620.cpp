#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>
#include<cmath>
#include<cstdio>
#include<tuple>
#include<bitset>
#include<map>

using namespace std;
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
#define ll long long
using lint=long long;
typedef pair<int,int> P;
const lint inf=1000000007;
const int MOD=1000000007;
signed main(){
  int n,k;cin>>n>>k;
  vector<int> x(n);
  rep(i,n){
      cin>>x[i];
  }
  vector<int> pulse,minus;
  pulse.push_back(0);
  ++k;
  rep(i,n){
      if(x[i]>=0)pulse.push_back(x[i]);
      else minus.push_back(x[i]);
  }
  reverse(ALL(minus));
  vector<lint> msm(n+5,0);
  vector<lint> psm(n+5,0);
  rep(i,minus.size()){
      msm[i+1]=minus[i];//+msm[i];
  }
  rep(i,pulse.size()){
      psm[i+1]=pulse[i];//+psm[i];
  }
  lint res=inf*inf;
  rep1(i,min((int)pulse.size(),k)){
      if(k-i>minus.size())continue;
      lint buf=2*psm[i]-msm[k-i];
      buf=min(buf,psm[i]-2*msm[k-i]);
      res=min(res,buf);
  }
  cout<<res<<"\n";
  return 0;
}