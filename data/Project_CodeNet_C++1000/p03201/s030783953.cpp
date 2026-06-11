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
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)
#define ALL(x) x.begin(),x.end()
using ll = long long;
using lint = long long;
typedef pair<int,int> P;
const lint inf=1e18+7;
const int MOD=1000000007;
signed main(){
  int n;cin>>n;
  map<int,int> memo;
  rep(i,n){
    int buf;cin>>buf;
    memo[buf]+=1;
  }
  auto it=memo.end();
  int res=0;
  while(it!=memo.begin()){
    --it;
    
    int nxt=1;
    int hoge=it->first;
    while(hoge>0){
      hoge/=2;
      nxt*=2;
    }
    //printf("value = %lld, nxt = %lld\n",it->first,nxt);
    if(it->first*2==nxt){
      res+=it->second/2;
      it->second=0;
      continue;
    }
    auto it2=memo.find(nxt-it->first);
    if(it2!=memo.end()){
      res+=min(it->second,it2->second);
      it2->second-=min(it->second,it2->second);
    }
    it->second=0;
  }
  cout<<res<<"\n";
  return 0;
}