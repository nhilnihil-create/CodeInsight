#include <cstdio>
#include <algorithm>

const int64_t INF=1e15;

void setmax(int64_t& x,int64_t y){
  x=std::max(x,y);
}

struct Block{
  int w,s,v;
  bool operator<(struct Block b)const{
    return s+w<b.s+b.w;
  }   
}blocks[1005];

int64_t dp[20001];

int main(){
  int N;
  scanf("%d",&N);
  for(int i=0;i<N;i++){
    scanf("%d %d %d",&blocks[i].w,&blocks[i].s,&blocks[i].v);
  }
  std::sort(blocks,blocks+N);
  std::fill(dp+1,dp+20001,-INF);
  for(int i=0;i<N;i++){
    for(int w=blocks[i].s;w>=0;w--){
      setmax(dp[w+blocks[i].w],dp[w]+blocks[i].v);
    }
  }
  printf("%ld\n",*std::max_element(dp,dp+20001));
  return 0;
}
