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
int a[MAXN];
vector <int> pos[30];
long long ans = 0;

int main() {

  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  for (int i = 0; i < n; i++) {
    for (int j = 0; j < 20; j++) {
      if ((a[i] & (1 << j))) {
        pos[j].push_back(i);
      }
    }
    int l = 0;
    for (int j = 0; j < 20; j++) {
      if (sz(pos[j]) >= 2) {
        int prev = pos[j][sz(pos[j]) - 2];
        l = max(l, prev + 1);
      }
    }
    ans += (i - l + 1);
  }

  cout << ans << endl;

  return 0;
}
