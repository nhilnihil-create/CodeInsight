#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <iomanip>

#include <vector>
#include <cstring>
#include <string>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>

#include <utility>
#include <list>

#include <cmath>
#include <algorithm>
#include <cassert>
#include <bitset>
#include <complex>
#include <climits>
#include <functional>
#include <unordered_set>
#include <unordered_map>
using namespace std;

typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back

#define debug(x) cerr << #x << " = " << x << " "


vector<int> move_of_string(string s, char left, char right)
{
  vector<int> ret;
  for (auto e : s)
    ret.pb(-(e==left) + (e==right));
  return ret;
}
bool solve(string s, string t, char left, char right, int range, int pos)
{
  vector<vector<int> > v = {move_of_string(s, left, right), move_of_string(t, left, right)};
  int n = v.front().size();
  ii valid = mp(1, range);
  for (int i = n-1; i >= 0; --i)
    for (int p = 1; p >= 0; --p)
      if (v[p][i] != 0)
        {
          if (v[p][i] == 1)
            if (p == 1) valid.first -= 1;
            else valid.second -= 1;
          else
            if (p == 1) valid.second += 1;
            else valid.first += 1;

          valid.first = max(1, valid.first);
          valid.second = min(range, valid.second);
          if (valid.first > valid.second) return false;
        }
  bool ret = valid.first <= pos && pos <= valid.second;
  return ret;
}

int main()
{
  int h, w, n, x, y;
  cin >> h >> w >> n >> x >> y;
  string s, t;
  cin >> s >> t;
  cout << ((solve(s, t, 'L', 'R', w, y) && solve(s, t, 'U', 'D', h, x)) ? "YES" : "NO") << endl;
}
