
#include <map>
#include <sstream>
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <queue>
#include <iostream>
#include <algorithm>

using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)
typedef long long ll;

int as[200000+10];
int bs[200000+10];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) {
    scanf("%d", &as[i]);
  }
  REP(i, n) {
    scanf("%d", &bs[i]);
  }

  int res = 0;
  REP(d, 29) {
    // cerr << "> " << d << endl;
    int mask = (1 << d) - 1;
    int target = 1 << d;
    vector<int> tas[2];
    vector<int> tbs[2];
    REP(i, n) {
      tas[as[i] & target ? 1 : 0].push_back(as[i] & mask);
      tbs[bs[i] & target ? 1 : 0].push_back(bs[i] & mask);
    }
    REP(i, 2) {
      sort(tas[i].begin(), tas[i].end());
      sort(tbs[i].begin(), tbs[i].end());
    }
    ll cur00 = 0;
    ll cur01 = 0;
    ll cur10 = 0;
    ll cur11 = 0;
    {
      // (0,0)carryあり
      int ib0 = (int)tbs[0].size() - 1;
      // (0,1)carryなし
      int ib1 = (int)tbs[1].size() - 1;;
      REP(ia, tas[0].size()) {
        while(ib0 >= 0 && tas[0][ia] + tbs[0][ib0] >= target) {
          --ib0;
        }
        cur00 += (int)tbs[0].size()-1 - ib0;
        while(ib1 >= 0 && tas[0][ia] + tbs[1][ib1] >= target) {
          --ib1;
        }
        cur01 += ib1+1;
      }
    }
    {
      // (1,1)carryあり
      int ib1 = (int)tbs[1].size() - 1;
      // (1,0)carryなし
      int ib0 = (int)tbs[0].size() - 1;
      REP(ia, tas[1].size()) {
        while(ib1 >= 0 && tas[1][ia] + tbs[1][ib1] >= target) {
          --ib1;
        }
        cur11 += (int)tbs[1].size()-1 - ib1;
        while(ib0 >= 0 && tas[1][ia] + tbs[0][ib0] >= target) {
          --ib0;
        }
        cur10 += ib0+1;
      }
    }

    if((cur00+cur01+cur10+cur11) % 2 == 1) {
      res |= 1 << d;
    }
  }
  printf("%d\n", res);

  return 0;
}
