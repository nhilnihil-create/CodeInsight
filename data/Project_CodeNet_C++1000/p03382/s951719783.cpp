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
  int x = *max_element(rbegin(a), rend(a));
  pair<int, int> best(-1, 0);
  for(int i = 0; i < n; i++) {
    if(a[i] != x) best = max(best, make_pair(f(x, a[i]), a[i]));
  }
  cout << x << " " << best.second << endl;
  return 0;
}
