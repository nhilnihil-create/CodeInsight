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

const int MAXN = 105000;

int st[MAXN];

int getSet(int x) {
  if (st[x] == x)
    return x;
  st[x] = getSet(st[x]);
  return st[x];
}

void unite(int a, int b) {
  a = getSet(a); b = getSet(b);
  if (rand() & 1)
    swap(a, b);
  st[a] = b;
}

int n, m;
int p[MAXN];
int ans;

int main() { 

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &p[i]);
    st[i] = i;
  }

  for (int i = 0; i < m; i++) {
    int from, to;
    scanf("%d %d", &from, &to);
    from--; to--;
    unite(from, to);
  }

  for (int i = 0; i < n; i++) {
    if (getSet(i) == getSet(p[i] - 1)) {
      ans++;
    }
  }

  cout << ans << endl;

  return 0;
}
