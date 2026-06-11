/// awoooooo

# include <bits/stdc++.h>
# define sz(x) (int)((x).size())

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair < int, int > pii;

const int N = (int)2e5 + 5;
const int inf = (int)1e9 + 7;

int n, m;
int u[N], cnta[N];
char c[N];
set < int > g[N], bad;

int main(){
  scanf("%d %d", &n, &m);
  for(int i = 1; i <= n; ++i){
    scanf(" %c", c + i);
  }
  for(int i = 1; i <= m; ++i){
    int x, y;
    scanf("%d %d", &x, &y);
    g[x].insert(y);
    g[y].insert(x);
  }
  for(int i = 1; i <= n; ++i){
    for(int j : g[i]){
      cnta[i] += (c[j] == 'A');
    }
    if(cnta[i] == 0 || cnta[i] == sz(g[i])){
      bad.insert(i);
      u[i] = 1;
    }
  }
  while(!bad.empty()){
    int v = *bad.begin();
    bad.erase(bad.begin());
    for(int i : g[v]){
      cnta[i] -= (c[v] == 'A');
      g[i].erase(v);
      if(u[i]) continue;
      if(cnta[i] == 0 || cnta[i] == sz(g[i])){
        u[i] = 1;
        bad.insert(i);
      }
    }
    g[v].clear();
  }
  for(int i = 1; i <= n; ++i){
    if(!u[i]){
      printf("Yes\n");
      return 0;
    }
  }
  printf("No\n");

  return 0;
}
