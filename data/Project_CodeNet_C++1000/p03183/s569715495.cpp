#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<unordered_map>
typedef unsigned long long ull;
typedef signed long long sll;
using namespace std;

#define INF 0x7FFFFFFFFFFFFFFF
#define BIG_PRIME 1000000007

struct Block{
  sll w;
  sll s;
  sll v;
  Block(sll W,sll S,sll V)
  {
    w=W;
    s=S;
    v=V;
  }
  bool operator<(const Block &rhs)const{
    return min(s,rhs.s-w)>min(rhs.s,s-rhs.w);
  }
};

int main()
{
  vector<Block> blocks;
  vector<sll> dp(20001,0);
  sll i,j,N,w,s,v;
  cin >> N;
  for(i=0;i<N;++i)
  {
    cin >> w >> s >> v;
    blocks.push_back(Block(w,s,v));
  }
  sort(blocks.begin(),blocks.end());
  
  for(i=0;i<N;++i)
  {
    for(j=0;j<=blocks[i].s;++j)
    {
      dp[blocks[i].s-j+blocks[i].w]=max(dp[blocks[i].s-j+blocks[i].w],dp[blocks[i].s-j]+blocks[i].v);
    }
  }
  sll value = 0;
  for(i=0;i<=20000;++i)
  {
    value = max(value,dp[i]);
  }
  
  cout << value;

  return 0;
}
