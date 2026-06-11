
#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int n;
int k;
int nQuery;
int vs[2000+10];

int main(void) {
  scanf("%d%d%d", &n, &k, &nQuery);
  set<int> ss;
  REP(i, n) {
    scanf("%d", &vs[i]);
    ss.insert(vs[i]);
  }

  int res = 2000000000;
  for(int v : ss) {
    vector<int> cands;
    { // init
      vector<int> sorted;
      REP(i, n) {
        if(vs[i] < v) {
          sort(sorted.begin(), sorted.end());
          REP(j, sorted.size() - k + 1) {
            cands.push_back(sorted[j]);
          }
          sorted.clear();
        } else {
          sorted.push_back(vs[i]);
        }
      }
      if((int)sorted.size() >= k) {
        sort(sorted.begin(), sorted.end());
        REP(j, sorted.size() - k + 1) {
          cands.push_back(sorted[j]);
        }
      }
    }
    if((int)cands.size() >= nQuery) {
      sort(cands.begin(), cands.end());
      res = min(res, cands[nQuery-1] - v);
    }
  }
  printf("%d\n", res);
  
  return 0;
}
