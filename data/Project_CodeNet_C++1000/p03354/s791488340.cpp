#include <bits/stdc++.h>
using namespace std;
int MAXN = 100001;
int N, M, ans = 0;
vector<int> Tree(MAXN, 0);

void init()
{
  for (int i = 1; i <= N; i++)
    Tree.at(i) = i;
}

int root(int x)
{
  if (Tree.at(x) == x)
    return x;
  else
    return Tree.at(x) = root(Tree.at(x));
}

bool same(int x, int y)
{
  return root(x) == root(y);
}

void unite(int x, int y)
{
  x = root(x);
  y = root(y);
  if (x == y)
    return;
  Tree.at(x) = y;
}

int main()
{
  cin >> N >> M;
  vector<int64_t> P(N + 1);
  for (int i = 1; i <= N; i++)
    cin >> P.at(i);
  init();
  int x, y;
  for (int i = 0; i < M; i++)
  {
    cin >> x >> y;
    unite(x, y);
  }
  for (int i = 1; i <= N; i++)
  {
    int p = P.at(i);
    if (same(i, p))
      ans++;
  }
  cout << ans << endl;
}