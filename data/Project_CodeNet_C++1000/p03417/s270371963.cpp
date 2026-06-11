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

int n, m;
long long ans;

int main() { 

  cin >> n >> m;

  if (n == 1 && m == 1) {
    ans = 1;
    cout << ans << endl;
    return 0;
  }

  ans = max(0ll, 1ll * (n - 2) * (m - 2));

  if (n == 1) {
    ans = max(0, m - 2);
  }
  if (m == 1) {
    ans = max(0, n - 2);
  }

  cout << ans << endl;

  return 0;
}
