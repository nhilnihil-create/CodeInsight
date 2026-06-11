#include <iostream>
#include <vector>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const nmax = 200000;
vector<int> g[1 + nmax];

pair<int,int> dfs(int node, int parent){
  pair<int,int> sol(0, node);
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    if(to != parent)
      sol = max(sol, dfs(to, node));
  }
  sol.first++;
  return sol;
}

int main()
{
  int n;
  cin >> n;
  for(int i = 1;i < n; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  pair<int,int> sol = dfs(dfs(1, 0).second, 0);

  if(sol.first % 3 == 2)
    cout << "Second";
  else
    cout << "First";
  return 0;
}
