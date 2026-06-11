#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define debug(x) (cerr << #x << " = " << x << endl;)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
#define FOR(it, b, e) for (typeof(b) it = (b); it != (e); ++it)
#define MSET(c, v) memset(c, v, sizeof(c))

const int INF = 0x3F3F3F3F;
const int NEGINF = 0xC0C0C0C0;
const int NULO = -1;
const double EPS = 1e-10;

inline int cmp(double x, double y = 0)
{
  if (fabs(x - y) < EPS)
    return 0;
  return x > y ? 1 : -1;
}

const int maxn = 1e5 + 10;

int n;

int test(string s, char c)
{
  int cnt = 0;
  int op = c - '0';
  for(const auto &x : s)
  { 
    if(x - '0' != op)
      cnt++;
    op ^= 1;
  }
  return cnt;
}

int main()
{
  ios::sync_with_stdio(false);
  string s;
  cin >> s;
  cout << min(test(s, '0'), test(s, '1')) << endl;
  return 0;
}