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

int n, m;
int a[MAXN];
map <long long, int> cnt;
long long ans;

int main() { 

  scanf("%d %d", &n, &m);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i]);
  }

  cnt[0] = 1;
  long long sum = 0;
  for (int i = 0; i < n; i++) {
    sum += a[i];
    long long mod = sum % m;
    ans += cnt[mod];
    cnt[mod]++;
  }

  cout << ans << endl;

  return 0;
}
