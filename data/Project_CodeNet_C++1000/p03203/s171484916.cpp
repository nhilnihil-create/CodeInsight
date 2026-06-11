#include <cstdio>
#include <algorithm>
#include <set>

std::set<int> walls[200005];

int main(){
  int H,W,N;
  scanf("%d %d %d",&H,&W,&N);
  for(int i=0;i<N;i++){
    int X,Y;
    scanf("%d %d",&X,&Y);
    walls[X].insert(Y);
  }
  int range=1;
  for(int x=1;x<H;x++){
    if(walls[x+1].size()&&*walls[x+1].begin()<=range){
      printf("%d\n",x);
      return 0;
    }
    if(!walls[x+1].count(range+1)){
      range++;
    }
  }
  printf("%d\n",H);
  return 0;
}
