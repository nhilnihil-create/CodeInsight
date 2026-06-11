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
#include<unordered_map>

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
int myPow(int x,int n){
    int res=1;
    int cur=x;
    while(n>0){
        if(n&1){
            res*=cur;
        }
        cur*=cur;
        n/=2;
    }
    return res;
}
class Node{
    public:
    int no;
    vector<P> edge;
};
signed main(){
  int l;cin>>l;
  vector<Node> node(30);
  --l;
  int bit=1;
  int rem=inf;
  int m=0;
  int n=0;
  rep(i,20){
      if(bit*2-1<=l){
          node[i].edge.push_back({i+1,bit});
          node[i].edge.push_back({i+1,0});
          m+=2;
      }
      bit*=2;
      if(bit*2-1>l){
          rem=bit;
          n=i+1;
          break;
      }
  }
  //cout<<n+1<<endl;
  for(int i=n-1;i>=0;--i){
      int sum=node[i].edge[0].second;
      if(l-rem+1>=sum){
          node[i].edge.push_back({n,rem});
          ++m;
          rem+=sum;
      }
  }
  printf("%lld %lld\n",n+1,m);
  rep(i,n){
      for(const auto& val:node[i].edge){
          printf("%lld %lld %lld\n",i+1,val.first+1,val.second);
      }
  }
  return 0;
}