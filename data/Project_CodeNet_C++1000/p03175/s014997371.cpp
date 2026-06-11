#include <bits/stdc++.h>
using namespace std;
#define ffor(n) for(int i = 0; i < n; i++)
#define fffor(n) for(int j = 0; j < n; j++)
int INF = 1e9 + 7;

struct node{
  long long white, black;
  node(long long _white, long long _black) {
    white = _white, black = _black;
  }
};

void dfs(int current_node, vector <vector <int>>& asd, vector <node>& v, int prev) {
  if (asd[current_node].size() == 1 && prev != -1) {
    v[current_node] = node(1, 1);
    return;
  }
  long long product = 1, product_2 = 1;
  for (int nextnode: asd[current_node]) {
    if (nextnode == prev) continue;
    dfs(nextnode, asd, v, current_node);
    product *= ((v[nextnode].white + v[nextnode].black) % INF);
    product %= INF;
    product_2 *= v[nextnode].white;
    product_2 %= INF;
  }
  v[current_node].black = product_2;
  v[current_node].white = product;
}

int main(void) {
  int n, a, b;
  cin >> n;
  vector <vector <int>> asd(n);
  ffor(n - 1) {
    cin >> a >> b;
    a--; b--;
    asd[a].push_back(b);
    asd[b].push_back(a);
  }
  
  vector <node> v(n, node(0, 0));
  dfs(0, asd, v, -1);
  
  cout << (v[0].white + v[0].black) % INF;
}