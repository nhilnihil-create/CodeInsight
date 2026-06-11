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

const int MAXN = 105;

int n = 100, m = 40;
int w, b;
char c[MAXN][MAXN];
bool used[MAXN][MAXN];

void dfs(int i, int j, char col) {
  if (i < 0 || i >= n || j < 0 || j >= m || used[i][j] || c[i][j] != col) {
    return;
  }
  const int di[] = {-1, 1, 0, 0};
  const int dj[] = {0, 0, -1, 1};
  used[i][j] = true;
  for (int k = 0; k < 4; k++) {
    dfs(i + di[k], j + dj[k], col);
  }
}

void comps() {
  int wc = 0, bc = 0;
  memset(used, 0, sizeof(used));
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      if (!used[i][j]) {
        if (c[i][j] == '#') {
          bc++;
        } else {
          wc++;
        }
        dfs(i, j, c[i][j]);
      }
    }
  }
  cerr << "White: " <<  wc << " black: " << bc << endl;
}

int main() { 

  cin >> w >> b;

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 20; j++) {
      c[i][j] = '#';
    }
  }
  for (int i = 1; i < 100; i += 2) {
    for (int j = 0; j < 20; j += 2) {
      c[i][j] = '.';
    }
  }
  c[99][19] = '.';

  for (int i = 0; i < 100; i++) {
    for (int j = 0; j < 20; j++) {
      c[i][20 + j] = '.';
    }
  }
  for (int i = 0; i < 100; i += 2) {
    for (int j = 1; j < 20; j += 2) {
      c[i][20 + j] = '#';
    }
  }
  c[0][20] = '#';

  // for (int i = 0; i < n; i++) {
  //   for (int j = 0; j < m; j++) {
  //     printf("%c", c[i][j]);
  //   }
  //   printf("\n");
  // }

  comps();

  int wc = 500, bc = 500;

  for (int j = 18; j >= 0; j -= 2) {
    for (int i = 98; i >= 2; i -= 2) {
      if (wc == w) {
        break;
      }
      c[i][j] = '.';
      wc--;
    }
    if (wc == w) {
      break;
    }
    c[99][j - 1] = '.';
    wc--;
  }

  for (int j = 21; j < 40; j += 2) {
    for (int i = 1; i <= 97; i += 2) {
      if (bc == b) {
        break;
      }
      c[i][j] = '#';
      bc--;
    }
    if (bc == b) {
      break;
    }
    c[0][j + 1] = '#';
    bc--;
  }

  cout << n << " " << m << endl;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      printf("%c", c[i][j]);
    }
    printf("\n");
  }
  comps();

  return 0;
}
