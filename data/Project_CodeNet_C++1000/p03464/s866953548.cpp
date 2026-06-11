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

int n;
int a[MAXN];

int main() { 

  cin >> n;
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  long long l = 2, r = 2;
  for (int i = n - 1; i >= 0; i--) {
    long long mn = 1ll * a[i] * ((l + a[i] - 1) / a[i]);
    long long mx = 1ll * a[i] * (r / a[i]);
    if (mn > r) {
      puts("-1");
      return 0;
    }
    l = mn; r = mx + a[i] - 1;
  }

  cout << l << " " << r << endl;

  return 0;
}
