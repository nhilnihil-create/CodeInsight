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

const int MAXN = 305;

int n;
vector <int> red[MAXN], blue[MAXN];

int main() { 

  cin >> n;
  for (int i = 0; i < n; i++) {
    int a, b;
    scanf("%d %d", &a, &b);
    red[a].push_back(b);
  }
  for (int i = 0; i < n; i++) {
    int c, d;
    scanf("%d %d", &c, &d);
    blue[c].push_back(d);
  }

  int ans = 0;
  multiset<int> st;
  for (int i = 0; i < 2 * n; i++) {
    sort(all(blue[i]));
    for (int y : blue[i]) {
      auto it = st.upper_bound(y);
      if (it != st.begin()) {
        it--;
        ans++;
        st.erase(it);
      }
    }
    for (int y : red[i]) {
      st.insert(y);
    }
  }

  cout << ans << endl;

  return 0;
}
