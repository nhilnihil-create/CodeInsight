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

const int MAXN = 2 * 105000;

int h, w, n;
int sr, sc;
string s, t;
pair<int, int> winH[MAXN], winV[MAXN];

int main() {

  scanf("%d %d %d", &h, &w, &n);
  scanf("%d %d\n", &sr, &sc);
  sr--; sc--;
  getline(cin, s);
  getline(cin, t); 

  winH[n] = {0, w - 1};
  winV[n] = {0, h - 1};
  for (int i = n - 1; i >= 0; i--) {
    int dh1 = 0, dh2 = 0;
    int dv1 = 0, dv2 = 0;
    if (s[i] == 'L') {
      dh1 = -1;
    } else if (s[i] == 'R') {
      dh1 = 1;
    } else if (s[i] == 'U') {
      dv1 = -1;
    } else {
      dv1 = 1;
    }
    if (t[i] == 'L') {
      dh2 = -1;
    } else if (t[i] == 'R') {
      dh2 = 1;
    } else if (t[i] == 'U') {
      dv2 = -1;
    } else {
      dv2 = 1;
    }

    winH[i] = winH[i + 1];
    winH[i] = {max(0, min(winH[i].first, winH[i].first - dh2)), min(w - 1, max(winH[i].second, winH[i].second - dh2))};
    winV[i] = winV[i + 1];
    winV[i] = {max(0, min(winV[i].first, winV[i].first - dv2)), min(h - 1, max(winV[i].second, winV[i].second - dv2))};

    winH[i] = {max(winH[i].first, winH[i].first - dh1), min(winH[i].second, winH[i].second - dh1)};
    winV[i] = {max(winV[i].first, winV[i].first - dv1), min(winV[i].second, winV[i].second - dv1)};

    // cerr << "V: " << winV[i].first << " " << winV[i].second << endl;
    // cerr << "H: " << winH[i].first << " " << winH[i].second << endl;

    if (winH[i].first > winH[i].second || winV[i].first > winV[i].second) {
      puts("NO");
      return 0;
    }
  }

  if (sr >= winV[0].first && sr <= winV[0].second && sc >= winH[0].first && sc <= winH[0].second) {
    puts("YES");
  } else {
    puts("NO");
  }

  return 0;
}
