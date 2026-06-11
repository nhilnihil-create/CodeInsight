#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef pair<ll, ll> l4;
typedef pair<double, double> dd;
#define mp make_pair
#define pb push_back
#define debug(x) cerr << #x << " = " << x << " "

const int N = 2e3+1;
int n, k, q, a[N];
int solve(int mini)
{
  multiset<int> tot;
  int cur = 1;
  while (cur <= n)
    {
      while (cur <= n && a[cur] < mini) ++cur;
      if (cur > n) break;
      multiset<int> tmp;
      while (cur <= n && a[cur] >= mini) tmp.insert(a[cur++]);
      while (tmp.size() >= k)
	{
	  tot.insert(*tmp.begin());
	  tmp.erase(tmp.begin());
	}
    }
  if (tot.size() < q) return INT_MAX;
  int ans = -(*tot.begin());
  for (int i = 1; i < q; ++i) tot.erase(tot.begin());
  ans += *tot.begin();
  return ans;
}
int main()
{
  while (~scanf("%d %d %d", &n, &k, &q))
    {
      set<int> st;
      for (int i = 1; i <= n; ++i) scanf("%d", a+i), st.insert(a[i]);
      int ans = INT_MAX;
      for (int i = 1; i <= n; ++i) ans = min(ans, solve(a[i]));
      printf("%d\n", ans);
    }

}
