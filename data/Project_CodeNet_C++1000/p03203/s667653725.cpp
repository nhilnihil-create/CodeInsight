#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <utility>
#include <queue>
#include <cassert>
#define maxW 200005
 
using namespace std;
typedef long long ll;
int H,W,n;
vector <int> blocks[maxW];
int main(){
  scanf("%d%d%d",&H,&W,&n);
  for(int i = 1;i <= n;i++){
    int x,y;
    scanf("%d%d",&x,&y);
    blocks[y].push_back(x);
  }
  for(int i = 1;i <= W;i++){
    blocks[i].push_back(H + 1);
    sort(blocks[i].begin(),blocks[i].end());
  }
  int cx = 1;
  int ans = blocks[1][0] - 1;
  for(int i = 2;i <= W;i++){
    cx++;
    while(cx <= H && binary_search(blocks[i].begin(),blocks[i].end(),cx)) cx++;
    if(cx <= H){
      ans = min(ans,*lower_bound(blocks[i].begin(),blocks[i].end(),cx) - 1);
    }else break;
  }
  printf("%d\n",ans);
  return 0;
}
