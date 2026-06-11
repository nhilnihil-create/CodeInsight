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

int a, b, c;
int x, y;
long long ans = 1e18;

int main() { 

  cin >> a >> b >> c >> x >> y;

  for (int i = 0; i <= 200000; i += 2) {
    long long cur = 1ll * i * c;
    int ac = i / 2, bc = i / 2;
    cur += 1ll * a * max(0, x - ac);
    cur += 1ll * b * max(0, y - bc);
    ans = min(ans, cur);
  }

  cout << ans << endl;

  return 0;
}
