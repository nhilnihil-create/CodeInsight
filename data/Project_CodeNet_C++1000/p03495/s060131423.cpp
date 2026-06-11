#include <bits/stdc++.h>

typedef long long ll;

#define rep(i, n) for (int i = 0; i < (n); ++i)
#define INF 10e7
#define MOD 1000000000 + 7
#define MAX 51000
#define all(x) (x).begin(), (x).end()
#define MX(x) *max_element(all(x))
#define MN(x) *min_element(all(x))

using namespace std;

int main(void)
{
  int n, k;
  cin >> n >> k;
  vector<int> a(n);
  rep(i, n) cin >> a[i];
  map<int, int> mp;
  rep(i, n) mp[a[i]]++;
  multiset<int> mst;
  for (auto i : mp)
    mst.insert(i.second);
  int ans = 0;
  while (mst.size() > k)
    ans += *mst.begin(), mst.erase(mst.begin());
  cout << ans << endl;
}