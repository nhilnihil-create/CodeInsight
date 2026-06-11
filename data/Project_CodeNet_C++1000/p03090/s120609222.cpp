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

int n;
vector< vector<int> > comps;
vector< pair<int, int> > edges;

int main() { 

  cin >> n;

  if (n & 1) {
    comps.push_back({n});
    n--;
  }
  for (int i = 1; i <= n / 2; i++) {
    comps.push_back({i, n - i + 1});
  }

  for (int i = 0; i < sz(comps); i++) {
    for (int v : comps[i]) {
      for (int j = i + 1; j < sz(comps); j++) {
        if (i == j) {
          continue;
        }
        for (int to : comps[j]) {
          edges.push_back({v, to});
        }
      }
    }
  }

  printf("%d\n", sz(edges));
  for (auto edge : edges) {
    printf("%d %d\n", edge.first, edge.second);
  }

  return 0;
}
