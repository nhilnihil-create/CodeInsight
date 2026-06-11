
#include <cstdio>
#include <algorithm>
#include <vector>
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
using namespace std;

int vs[200];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &vs[i]);
  }
  int maxi = 0;
  int mini = 0;
  int maxIdx = 0;
  int minIdx = 0;
  REP(i, n) {
    if(maxi < vs[i]) {
      maxIdx = i;
      maxi = vs[i];
    }
    if(mini > vs[i]) {
      minIdx = i;
      mini = vs[i];
    }
  }
  vector<pair<int,int> > res;
  if(abs(maxi) > abs(mini)) {
    REP(i, n) {
      if(i != maxIdx) {
        res.push_back(make_pair(maxIdx, i));
      }
    }
    REP(i, n-1) {
      res.push_back(make_pair(i, i+1));
    }
  } else {
    REP(i, n) {
      if(i != minIdx) {
        res.push_back(make_pair(minIdx, i));
      }
    }
    REP(i, n-1) {
      res.push_back(make_pair(n-i-1, n-i-2));
    }
  }

  printf("%d\n", (int)res.size());
  REP(i, res.size()) {
    printf("%d %d\n", res[i].first+1, res[i].second+1);
  }
  return 0;
}
