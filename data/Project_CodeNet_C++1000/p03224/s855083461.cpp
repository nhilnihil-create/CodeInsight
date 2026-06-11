
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#define REP(i, n) for(int i = 0; i < (int)(n); ++i)

typedef long long ll;


vector<int> vs[500];

int main(void) {
  int n;
  scanf("%d", &n);
  ll k = 1;
  while(k*(k-1) < 2*n) {
    ++k;
  }
  if(k*(k-1) != 2*n) {
    puts("No");
    return 0;
  }
  // cerr << "> " << k << endl;
  int cur = 1;
  REP(i, k-1) {
    int start = cur;
    while((int)vs[i].size() < k-1) {
      vs[i].push_back(cur);
      ++cur;
    }
    REP(j, cur-start) {
      vs[i+j+1].push_back(start+j);
    }
  }
  puts("Yes");
  printf("%lld\n", k);
  REP(i, k) {
    printf("%lld", k-1);
    REP(j, k-1) {
      printf(" %d", vs[i][j]);
    }
    puts("");
  }
  
  return 0;
}
