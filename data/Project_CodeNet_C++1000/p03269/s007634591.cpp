#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<ll>> matrix;

void solve() {
  int desire;
  cin >> desire;
  desire--;
  vector<pii> edge;
  vector<int> weight;
  {
    int a = 1;
    for(int i = 19; i >= 2; i--) {
      edge.push_back({i, i+1}); weight.push_back(0);
      edge.push_back({i, i+1}); weight.push_back(a);
      a *= 2;
    }
  }
  int a = (1 << 18) - 1;
  int d = 2;
  while(desire > 0) {
    while(desire >= a) {
      edge.push_back({1, d});
      weight.push_back(desire - a);
      desire -= a + 1;
    }
    a /= 2;
    d++;
  }
  if(desire == 0) {
    edge.push_back({1, 20});
    weight.push_back(0);
  }
  cout << 20 << " " << edge.size() << "\n";
  for(int i = 0; i < edge.size(); i++) {
    cout << edge[i].first << " " << edge[i].second << " " << weight[i] << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  /*
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
  */
}
