// includes {{{
#include<iostream>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<tuple>
#include<cmath>
#include<random>
#include<cassert>
#include<bitset>
#include<cstdlib>
// #include<deque>
// #include<multiset>
// #include<cstring>
// #include<bits/stdc++.h>
// }}}
using namespace std;
using ll = long long;

int f(int a, int b) {
  return min(a - b, b);
}

int main() {
  std::ios::sync_with_stdio(false), std::cin.tie(0);
  int n;
  cin >> n;
  vector<int>a(n);
  for(auto &e:a) cin >> e;
  sort(rbegin(a), rend(a));
  tuple<double, int, int> best(-1, 0, 0);
  int head = 0;
  for(int i = 0; i < n; i++) {
    while(head + 1 < n && (i >= head || f(a[i], a[head]) < f(a[i], a[head + 1]))) head++;
    auto d = make_tuple(lgamma(a[i] + 1) - lgamma(a[head] + 1) - lgamma(a[i] - a[head] + 1), a[i], a[head]);
    best = max(best, d);
  }
  cout << get<1>(best) << " " << get<2>(best) << endl;
  return 0;
}
