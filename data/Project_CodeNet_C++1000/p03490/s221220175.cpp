
#include <cstdio>
#include <map>
#include <iostream>
#include <cstring>
#include <vector>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;
typedef long long ll;


// 最初は右向いてる
// 奇数番目と偶数番目がx軸y軸で云々か。それぞれでPARTITION
// 最初だけは向きが固定なので、進んだところから開始するのが良さそう。
// 

char buf[8010];

vector<int> xs;
vector<int> ys;


bool dp[16010];

bool isOK(vector<int> vs, int target) {
  memset(dp, 0, sizeof dp);
  dp[0] = true;
  // REP(i, 10) {
  //   printf("%d", dp[i]);
  // }
  // printf("\n");
  int sum = 0;
  REP(i, vs.size()) {
    int v = vs[i];
    sum += v;
    if(v) {
      for(int j = 8000-v; j >= 0; --j) {
        dp[j+v] = dp[j+v] || dp[j];
      }
    }
  }
  // REP(i, 10) {
  //   printf("%d", dp[i]);
  // }
  // printf("\n");
  int tt = sum-target;
  if(tt % 2 == 1 || tt < 0) {
    return false;
  }
  return dp[tt/2];
}

int main(void) {
  int x, y;
  scanf("%s%d%d", buf, &x, &y);
  int cur = 0;
  int dir = 0;
  int n = strlen(buf);
  REP(i, n) {
    if(buf[i] == 'F') {
      ++cur;
    } else {
      if(dir == 0) {
        x -= cur;
      } else if(dir % 2 == 0) {
        xs.push_back(cur);
      } else {
        ys.push_back(cur);
      }
      ++dir;
      cur = 0;
    }
  }
  // last
  if(dir == 0) {
    x -= cur;
  } else if(dir % 2 == 0) {
    xs.push_back(cur);
  } else {
    ys.push_back(cur);
  }
  // cerr << "(" << x << "," << y << ")" << endl;
  puts(isOK(xs, abs(x)) && isOK(ys, abs(y)) ? "Yes" : "No");
  
  return 0;
}
