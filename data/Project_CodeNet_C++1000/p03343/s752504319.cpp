#include <iostream>
#include <fstream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <cstdlib>
#include <cstdio>
#include <string>
#include <cstring>
#include <cassert>
#include <utility>
#include <iomanip>
#include <chrono>
#include <random>
#include <bitset>

using namespace std;

#define sz(x) (int) x.size()
#define unique(x) x.erase(unique(x.begin(), x.end()), x.end())
#define all(a) a.begin(), a.end()
#define sqr(x) ((x) * (x)) 
#define y1 aksjdaskdjksjfksdjf
#define left kdnvldvoiwejifejg
#define right lkdsjflksdjfdjfk
#define prev asdasfsadjkjsdfjs
#define tm aklsjdasjdasjdkdjjf
#define lcm hddalkwjeidjjhasda
#define random_shuffle asdasdd

const int MAXN = 2050;

int n, k, qn;
int a[MAXN];
int b[MAXN];
int ans = 1000 * 1000 * 1000;

bool ok(int mn, int mx) {
  int can = 0;
  set < pair<int, int> > st;  
  set < int > st2;
  for (int i = 0; i < n; i++) {
    if (a[i] < mn) {
      st.clear();
      st2.clear();
      continue;
    }
    if (sz(st) == k) {
      int idx = *st2.begin();
      st2.erase(st2.begin());
      st.erase({a[idx], idx});
    }
    st.insert({a[i], i});
    st2.insert(i);
    if (sz(st) == k && (*(st.begin())).first <= mx) {
      can++;
      st2.erase((*st.begin()).second);
      st.erase(st.begin());
    }
  }
  // cerr << mn << " " << mx << " " << can << endl;
  return can >= qn;
}

int main() { 

  scanf("%d %d %d", &n, &k, &qn);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
    b[i] = a[i];
  }

  sort(b, b + n);
  /* for (int i = 0; i < n; i++) {
    cout << lower_bound(b, b + n, a[i]) - b << endl;
  } */

  int r = 0;
  for (int i = 0; i < n; i++) {
    int mn = b[i];
    if (r < i) {
      r = i;
    }
    while (r < n && !ok(mn, b[r])) {
      r++;
    }
    if (r < n) {
      // cerr << i << " " << l << " " << b[l] - mn << " " << mn << " " << b[l] << endl;
      ans = min(ans, b[r] - mn);
    }
  }

  cout << ans << endl;

  return 0;
}
