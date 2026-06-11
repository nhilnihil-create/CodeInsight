#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <math.h>
#include <cassert>
#define rep(i,n) for(int i = 0; i < n; ++i )
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int x1,y1,x2,y2;
  cin >> x1 >> y1 >> x2 >> y2;

  int dx = x2-x1, dy = y2-y1;
  int x3 = x2-dy;
  int y3 = y2+dx;
  dx = x3-x2, dy = y3-y2;
  int x4 = x3-dy;
  int y4 = y3+dx;
  printf("%d %d %d %d\n",x3,y3,x4,y4);
}
