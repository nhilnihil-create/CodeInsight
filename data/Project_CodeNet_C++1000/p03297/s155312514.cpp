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

long long a, b, c, d;

long long gcd(long long a, long long b) {
  if (b == 0)
    return a;
  return gcd(b, a % b);
}

void solve() {
  cin >> a >> b >> c >> d;

  if (d < b || a < b) {
    puts("No");
    return;
  }

  long long diff = max(0ll, a - c);
  long long cur = a - (diff / b) * b;
  if (cur > c) {
    if (cur - b < 0) {
      puts("No");
      return;
    }
    cur -= b;
  }
  
  if (c >= b || d == b) {
    puts("Yes");
    return;
  }

  long long from = c + 1, to = b - 1;
  if (from > to) {
    puts("Yes");
    return;
  }
  // cerr << cur << " " << from << " " << to << " " << d - b << endl;

  long long g = gcd(b, d);

  from = ((from - a) % b + b) % b;
  to = ((to - a) % b + b) % b;

  if (from > to) {
    puts("Yes");
    return;
  }

  if (from / g == to / g && from % g > 0) {
    puts("Yes");
  } else {
    puts("No");
  }
}

int main() { 

  int tn;
  scanf("%d\n", &tn);
  while (tn--) {
    solve();
  }

  return 0;
}
