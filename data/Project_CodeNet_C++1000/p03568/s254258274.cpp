#include <bits/stdc++.h>
using namespace std;
#define rep(i, a) for(int i=0; i<(int)(a); i++)
typedef long long ll;

int n;
vector<int> a(11);
vector<vector<int>> b;

void dfs(int t, vector<int> v = vector<int>()) {
  if ((int)v.size() >= n) {
    b.push_back(v);
    return;
  }
  for (int i=-1; i<=1; i++) {
    v.push_back(a[t]-i);
    dfs(t+1, v);
    v.pop_back();
  }
}

int main()
{
  cin >> n;
  rep(i, n) cin >> a[i];
  dfs(0);
  int ans = 0;
  for (auto v:b) {
    for (auto c:v) {
      if (c%2==0) {
        ans++;
        break;
      }
    }
  }
  cout << ans << endl;

  return 0;
}
