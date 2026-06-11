#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;

const int N = 2e5+1;
const int NN = 2 * N;
char s[N+1];
int n, m;
vector<int> g[NN];
int in[NN];
inline void add(int x, int y)
{
  g[x].pb(y);
  ++in[y];
}
int main()
{
  scanf("%d %d %s", &n, &m, s+1);
  for (int i = 1; i <= m; ++i)
    {
      int a, b; scanf("%d %d", &a, &b);
      if (s[a] != s[b])
        add(2*a-1, 2*b), add(2*b-1, 2*a);
      else
        add(2*a, 2*b-1), add(2*b, 2*a-1);
    }
  queue<int> q;
  for (int i = 1; i <= 2*n; ++i)
    if (in[i] == 0) q.push(i);
  int vis = 0;
  while (!q.empty())
    {
      ++vis;
      int cur = q.front(); q.pop();
      for (auto nxt : g[cur])
        if (--in[nxt] == 0)
          q.push(nxt);
    }
  puts(vis == 2*n?"No":"Yes");

}
