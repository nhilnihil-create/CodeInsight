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

const int MAXN = 205000;

int n;
int a[MAXN], b[MAXN];
vector<int> v;
long long ans;

int main() { 

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d %d", &a[i], &b[i]);
  }

  int diff = 0;
  for (int i = 0; i < n; i++) {
    if (a[i] != b[i]) {
      diff++;
    }
    if (a[i] <= b[i]) {
      ans += b[i];
    } else {
      v.push_back(b[i]);
    }
  }

  sort(all(v));
  reverse(all(v));
  for (int i = 0; i + 1 < sz(v); i++) {
    ans += v[i];
  }

  if (diff == 0) {
    ans = 0;
  }

  cout << ans << endl;

  return 0;
}
