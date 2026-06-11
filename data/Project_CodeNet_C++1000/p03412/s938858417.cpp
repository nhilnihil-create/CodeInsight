
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
int tas[200000+10];
int tbs[200000+10];

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
    int mask = (1 << (d+1)) - 1;
    int target = 1 << d;
    REP(i, n) {
      tas[i] = as[i] & mask;
      tbs[i] = bs[i] & mask;
    }
    sort(tbs, tbs + n);
    ll cur = 0;
    REP(i, n) {
      int x1 = lower_bound(tbs, tbs + n, 2*target-tas[i]) - lower_bound(tbs, tbs + n, 1*target-tas[i]);
      int x2 = lower_bound(tbs, tbs + n, 4*target-tas[i]) - lower_bound(tbs, tbs + n, 3*target-tas[i]);
      cur += x1;
      cur += x2;
    }
    if(cur % 2 == 1) {
      res |= 1 << d;
    }
  }
  printf("%d\n", res);

  return 0;
}
