#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int const nmax = 200000;
vector<int> g[1 + nmax];
int a[1 + nmax], b[1 + nmax];
int active[1 + nmax];

int main()
{
  int n, m;
  cin >> n >> m;
  string s;
  cin >> s;
  s = "#" + s;
  for(int i = 1; i <= m; i++){
    int x, y;
    cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
    if(s[y] == 'A')
      a[x]++;
    else
      b[x]++;

    if(s[x] == 'A')
      a[y]++;
    else
      b[y]++;
  }
  queue<int> q;
  for(int i = 1;i <= n; i++)
    if(a[i] == 0 || b[i] == 0) {
      q.push(i);
      active[i] = 0;
    } else
      active[i] = 1;

  while(0 < q.size()){
    int node = q.front();
    q.pop();
    for(int h = 0; h < g[node].size(); h++){
      int to = g[node][h];
      if(s[node] == 'A')
        a[to]--;
      else
        b[to]--;
      if(active[to] == 1 && (a[to] == 0 || b[to] == 0)){
        q.push(to);
        active[to] = 0;
      }
    }
  }

  for(int i = 1;i <= n; i++)
    if(0 < active[i]) {
      cout << "Yes";
      return 0;
    }
  cout << "No";
  return 0;
}
