#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct blk {
  long long w, s, v;
};


bool mysort(const blk& a, const blk& b) {
  if (a.w < b.w && a.s <= b.s) return true;
  if (a.w == b.w && a.s <= b.s) return true;
  if (a.w < b.w && a.s == b.s) return true;

  auto x = min(a.s, b.s-a.w);
  auto y = min(b.s, a.s-b.w);

  if (x > y) return true;
  if (x == y && a.s < b.s) return true;
  if (x == y && a.w < b.w) return true;
  return false;
}

vector<vector < long long > > F( 1000+10, vector<long long>(10000+10, 0));

int main() {
  long long N;
  cin >> N;

  vector<blk> lst(N);
  long long naxs= 1;
  for (long long i=0; i < N; i++) {
    long long mys;
    cin >> lst[i].w >> mys >> lst[i].v;
    lst[i].s = mys;
    naxs = max(naxs, mys);
  }

  stable_sort(lst.begin(), lst.end(), mysort);
  reverse(lst.begin(), lst.end());
  // for(auto i=0; i<N;i++) printf("%d %d %d\n", lst[i].w, lst[i].s, lst[i].v);
  // F[i, s],  blk 0..i, with solid s

  F[0][ lst[0].s ] = lst[0].v;

  for(long long i=1; i< N; i++) {
    long long is = lst[i].s;
    for(long long s=0; s<=naxs; s++) { F[i][s] = F[i-1][s]; }

    for(long long s=0; s<=is; s++) {
      long long a = 0;

      if (s + lst[i].w <= naxs) { a = F[i-1][s + lst[i].w ]; }

      F[i][s] = max( F[i][s],  a + lst[i].v);
    }

    // s == is
    for(auto s=is; s<=naxs; s++) {
      long long a=0;
      if (s + lst[i].w <= naxs) { a = F[i-1][s + lst[i].w ]; } 
      F[i][is] = max( F[i][is], a  + lst[i].v);
    }
  }

  long long ans = -1;
  for(long long i=0; i< N; i++) {
    for(long long s=0; s<=naxs; s++) ans = max(ans, F[i][s]);
  }

  cout << ans << endl;

  return 0;
}