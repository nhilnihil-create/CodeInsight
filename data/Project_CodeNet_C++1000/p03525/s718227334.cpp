#include <bits/stdc++.h>
#include <vector>
#include <cmath>
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
#define REP2(i, m, n) for (int i = (m); i < (int)(n); ++i)
#define REPR(i, n) for (int i = (n)-1; i >= 0; --i)
#define REPR2(i, m, n) for (int i = (n)-1; i >= (m); --i)
#define REPx(x, a) for(auto x : a)
#define ALL(a) a.begin(), a.end()
#define SORT(a) sort(ALL(a))
#define SORTG(a) sort(ALL(a), greater<int>())
#define REVERSE(a) reverse(ALL(a))
#define bit_search(bit, n) REP(bit, 1<<(n))
#define bit_check(bit, i) (bit>>(i)) & 1
#define setpre(n) fixed << setprecision((n))
#define UNIQUE(a) do {SORT(a); (a).erase(unique(ALL(a)), (a).end());} while(0)
#define MAX(a) *max_element(ALL(a))
#define MIN(a) *min_element(ALL(a))
#define bisect_left(a, x) lower_bound(ALL(a), (x)) - a.begin()
#define bisect_right(a, x) upper_bound(ALL(a), (x)) - a.begin()
#define INPUT(a) REP(i, a.size()) cin >> a[i];
#define INPUTP(a) REP(i, a.size()) cin >> a[i].first >> a[i].second;
#define ENDL cout << endl;
using namespace std;
using ll = long long;
using ld = long double;
using PII = pair<int, int>;
using VPII = vector<PII>;
using VI = vector<int>;
using VVI = vector<VI>;
using Vll = vector<ll>;
using VVll = vector<Vll>;
using VC = vector<char>;
using VS = vector<string>;
using VB = vector<bool>;
const int INF = 1e9;
const ll MOD = 1e9 + 7;

VI ct(13, 0);
VB table(24, false);
VI uni;

int min_dis()
{
  int now = 0, pre = 0;
  int res = INF;
  REP(i, 23)
  {
    now++;
    if (table[now])
    {
      res = min(res, now-pre);
      pre = now;
    }
  }
  res = min(res, 24-pre);
  return res;
}

int main()
{
  int N;
  cin >> N;
  REP(i, N)
  {
    int d;
    cin >> d;
    ct[d]++;
  }
  ct[0]++;
  table[0] = true;
  if (MAX(ct) > 2 || ct[0] > 1 || ct[12] > 1)
  {
    cout << 0 << endl;
    return 0;
  }
  REP(i, 13)
  {
    if (i == 0 || i == 12) {if (ct[i] > 0) table[i] = true;}
    else
    {
      if (ct[i] == 1) uni.push_back(i);
      if (ct[i] == 2)
      {
        table[i] = true;
        table[24-i] = true;
      }
    }
  }
  int ans = 0;
  int len = uni.size();
  bit_search(bit, len)
  {
    VI set;
    REP(i, len)
    {
      if (bit_check(bit, i)) {table[uni[i]] = true; set.push_back(uni[i]);}
      else {table[24-uni[i]] = true; set.push_back(24-uni[i]);}
    }
    ans = max(ans, min_dis());
    REPx(x, set) table[x] = false;
  }

  cout << ans << endl;

  return 0;
}
