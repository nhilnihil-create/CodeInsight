#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;
const ll mod = 1000000007;

bool compare_by_second(pair<int,int> a, pair<int,int> b)
{
  if (a.second != b.second) {
    return a.second < b.second;
  }
  return a.first < b.first;
}

int main()
{
  int n, m; cin >> n >> m;
  vector<pair<int, int>> v(m);
  rep(i, m) {
    int a,b; cin>>a>>b;
    a--; b--;
    v[i] = make_pair(a, b);
  }
  sort(v.begin(),v.end(), compare_by_second);
  int x = v[0].second;
  int y = v[0].first;
  int ans = 1;
  rep(i, m) {
    y = max(y, v[i].first);
    if (y >= x) {
      x = v[i].second;
      ans++;
    }
  }
  cout << ans << endl;

  return 0;
}
