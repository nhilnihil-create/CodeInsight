#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;

using ll = long long;

const int INF = 1001001001;
const ll INF_LL = 1001001001001001001LL;

int main(void){
  int x1,y1,x2,y2; cin >> x1 >> y1 >> x2 >> y2;

  int dx = x2-x1,dy = y2-y1;
  int x3 = x2-dy,y3 = y2+dx;
  int x4 = x3-dx,y4 = y3-dy;

  printf("%d %d %d %d\n",x3,y3,x4,y4);
  
  return 0;
}
