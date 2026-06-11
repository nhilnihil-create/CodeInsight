#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <tuple>
#include <map>
using namespace std;
typedef long long ll;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
#define repd(i, a, b) for (ll i = (ll)(a); i < (ll)(b); i++)
#define repdm(i, a, b) for (ll i = (ll)(a); i > (ll)(b); i--)

int N, A, B, C;
int seq[4] = {0, 1, 2, 3};
int ANS = 100000;

int calcMP(map<int, int> m)
{
  if (m[1] == 0 || m[2] == 0 || m[3] == 0)
    return 10000;
  return abs(A - m[1]) + abs(B - m[2]) + abs(C - m[3]);
}

int dfs(int depth, int l[], map<int, int> m, int mp)
{
  if (depth == 0)
  {
    mp += calcMP(m);
    return mp;
  }

  for (auto s : seq)
  {
    int tmp = mp;
    map<int, int> mm = m;
    if (mm[s] == 0)
    {
      mm[s] = l[depth - 1];
    }
    else
    {
      mm[s] += l[depth - 1];
      if (s != 0)
        tmp += 10;
    }
    tmp = dfs(depth - 1, l, mm, tmp);
    ANS = min(ANS, tmp);
  }

  return ANS;
}

int main()
{
  cin >> N >> A >> B >> C;
  int l[N];
  rep(i, N) cin >> l[i];
  int mp = 0;

  map<int, int> m{
      {0, 0}, {1, 0}, {2, 0}, {3, 0}};

  dfs(N, l, m, mp);

  cout << ANS;
}