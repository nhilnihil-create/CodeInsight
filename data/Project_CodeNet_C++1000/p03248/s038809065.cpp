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

const int MAXN = 100500;

int n;
string s;
int node = 0;
vector < pair<int, int> > ans;
int l, r;

bool can(int pos) {
  return s[pos - 1] == '1';
}

void connect(int a, int b) {
  ans.push_back(make_pair(a, b));
}

int main() { 

  getline(cin, s);
  n = sz(s);

  if (!can(1) || !can(n - 1) || can(n)) {
    puts("-1");
    return 0;
  }
  for (int i = 1; i < n; i++) {
    if (can(i) && !can(n - i)) {
      puts("-1");
      return 0;
    }
  }

  l = 2, r = n - 2;
  while (!can(l)) {
    l++;
  }
  while (!can(r)) {
    r--;
  }

  if (r == 1) {
    connect(1, 2);
    for (int i = 0; i < n - 2; i++) {
      connect(2, 2 + i + 1);
    }
  } else {
    connect(1, 2);
    node = 3;
    for (int i = 0; i < l - 1; i++) {
      connect(1, node);
      node++;
    }
    int rightNode = 2;
    while (true) {
      int prev = r;
      r--;
      while (!can(r)) {
        r--;
      }
      if (r <= l) {
        while (node <= n) {
          connect(rightNode, node);
          node++;
        }
        break;
      } else {
        for (int i = 0; i < prev - r; i++) {
          connect(rightNode, node);
          node++;
        }
        rightNode = node - 1;
      }
    }
  }

  for (auto p : ans) {
    printf("%d %d\n", p.first, p.second);
  }

  return 0;
}
