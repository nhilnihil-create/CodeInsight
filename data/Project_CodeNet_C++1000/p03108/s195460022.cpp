#include <bits/stdc++.h>
using namespace std;
int MAXN = 100010;
vector<int> Tree(MAXN, 0), Size(MAXN, 1);

void init(int N)
{
  for (int i = 1; i <= N; i++)
    Tree.at(i) = i;
}

int root(int x)
{
  if (Tree.at(x) == x)
    return x; // 根
  else
    return Tree.at(x) = root(Tree.at(x)); // 経路圧縮
}

void unite(int x, int y)
{
  x = root(x);
  y = root(y);
  if (x == y)
    return;
  Tree.at(x) = y;
  Size.at(x) = Size.at(x) + Size.at(y);
  Size.at(y) = Size.at(x);
}

int main()
{
  int64_t N, M, a, b, ans = 0, z = 0;
  cin >> N >> M;
  init(N);
  vector<pair<int64_t, int64_t>> vp;
  for (int i = 0; i < M; i++)
  {
    cin >> a >> b;
    vp.push_back(make_pair(a, b));
  }
  stack<int64_t> A;
  for (int i = M - 1; i >= 0; i--)
  {
    tie(a, b) = vp.at(i);
    int64_t prv_a = Size.at(root(a)), prv_b = Size.at(root(b));
    unite(a, b);
    int64_t prv = (prv_a * (prv_a - 1) / 2) + (prv_b * (prv_b - 1) / 2);
    int64_t s = Size.at(root(a));
    A.emplace(max(z, (s * (s - 1) / 2) - prv));
  }
  while (!A.empty())
  {
    ans += A.top();
    cout << ans << endl;
    A.pop();
  }
}