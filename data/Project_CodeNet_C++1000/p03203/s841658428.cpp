
#include <cassert>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <iostream>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
#define FOR(i, c) for(__typeof((c).begin()) i = (c).begin(); i != (c).end(); ++i)
using namespace std;
typedef long long ll;

int n, nRow, nCol;

pair<int,int> ps[200000+10];
vector<pair<int,int> > rs[200000+10];

int main(void) {
  scanf("%d%d%d", &nCol, &nRow, &n);
  REP(i, n) {
    int c, r;
    scanf("%d%d", &c, &r);
    ps[i] = make_pair(r-1, c-1);
  }
  sort(ps, ps + n);

  // 各行をrangeに分割
  int lastR = 0;
  int lastC = 0;
  REP(idx, n) {
    int r = ps[idx].first;
    int c = ps[idx].second;
    for(; lastR < r; ++lastR) {
      int ced = nCol;
      if(lastC < ced) {
        rs[lastR].push_back(make_pair(lastC, ced));
      }
      lastC = 0;
    }
    int ced = c;
    if(lastC < ced) {
      rs[r].push_back(make_pair(lastC, ced));
    }
    lastC = c+1;
  }
  for(; lastR < nRow; ++lastR) {
    int ced = nCol;
    if(lastC < ced) {
      rs[lastR].push_back(make_pair(lastC, ced));
    }
    lastC = 0;
  }
  // 上から、到達可能なrangeを保持しながら進む
  // 答えはminC
  int res = nCol;
  pair<int,int> curRange = make_pair(-1, 1);
  REP(i, nRow) {
    const vector<pair<int,int> > &row = rs[i];
    int bg1 = curRange.first + 1;
    int ed1 = curRange.second;
    REP(i2, row.size()) {
      int bg2 = row[i2].first;
      int ed2 = row[i2].second;
      if(ed2 <= bg1) {
        continue;
      } else if(ed1 <= bg2) {
        break;
      } else {
        res = min(res, ed2);
        curRange = make_pair(max(bg1, bg2), ed2);
        break;
      }
    }
  }
  
  cout << res << endl;
  return 0;
}
