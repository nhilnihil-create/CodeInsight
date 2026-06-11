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

int n, k;
long long ans;

long long calc(int cnt) {
  long long res = 1ll * cnt * (cnt - 1) * (cnt - 2);
  res += cnt;
  res += 1ll * cnt * (cnt - 1) * 3;
  return res;
}

int main() { 

  cin >> n >> k;

  if (k == 1) {
    ans = calc(n);
  } else {
    ans = calc(n / k);
    if (k % 2 == 0) {
      ans += calc((n / (k / 2)) - (n / k));  
    }
  }

  cout << ans << endl;

  return 0;
}
