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
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
  int m,k;cin>>m>>k;
  if(m==0){
      if(k==0){
          printf("0 0\n");
      }
      else cout<<-1<<"\n";
      return 0;
  }
  if(m==1){
      if(k==0)printf("0 0 1 1\n");
      else cout<<-1<<"\n";
      return 0;
  }
  if(k>(1<<m)-1){
      cout<<-1<<"\n";
      return 0;
  }
  vector<int> t;
  vector<int> r;
  if(k==0){
      rep(i,(1<<m)){
          cout<<i<<" "<<i<<" ";
      }
      cout<<endl;
      return 0;
  }
  rep1(i,(1<<m)-1){
      if(i!=k)t.push_back(i);
  }
  r=t;
  reverse(ALL(r));
  printf("0 ");
  for(auto& val:t){
      cout<<val<<" ";
  }
  cout<<k<<" ";
  for(auto& val:r){
      cout<<val<<" ";
  }
  cout<<0<<" "<<k<<endl;
  return 0;
}