#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cassert>
#include <map>

using namespace std;

#define MIN(a, b) (((a) < (b)) ? (a) : (b))
#define MAX(a, b) (((a) < (b)) ? (b) : (a))
using ll = long long;
using ld = long double;

int const nmax = 100000;
ll dist[1 + nmax];
int ind[1 + nmax], sz[1 + nmax];
bool compare(int x, int y){
  return dist[x] < dist[y];
}

vector<int> g[1 + nmax];
int level[1 + nmax];

ll dfs(int node){
  ll result = level[node];
  for(int h = 0; h < g[node].size(); h++){
    int to = g[node][h];
    level[to] = level[node] + 1;
    result += dfs(to);
  }
  return result;
}

int main()
{
  int n;
  cin >> n;
  map<ll,int> code;
  for(int i = 1; i <= n; i++)
    cin >> dist[i];
  for(int i = 1; i <= n; i++) {
    ind[i] = i;
    sz[i] = 1;
    code[dist[i]] = i;
  }
  sort(ind + 1, ind + n + 1, compare);

  for(int i = n; 1 < i; i--){
    int node = ind[i];
    int far = code[dist[node] + sz[node] - (n - sz[node])];
    if(far == 0){
      cout << "-1";
      return 0;
    } else {
      g[far].push_back(node);
      sz[far] += sz[node];
    }
  }
  ll result = dfs(ind[1]);
  if(dist[ind[1]] == result){
    for(int i = 1;i <= n; i++)
      for(int h = 0; h < g[i].size(); h++)
        cout << i << " " << g[i][h] << '\n';
  } else
    cout << -1;
  return 0;
}
