#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

struct tri
{
  int w, s;
  ll v;
  tri(int w, int s, ll v)
    : w(w), s(s), v(v) {}
  bool operator<(const tri& t) const
  {
    return w + s < t.w + t.s;
  }
};

const int MAX = 1111;
ll dp[MAX][MAX*20+1];

int main()
{
  ios_base::sync_with_stdio(false);
  cin.tie(0),cout.tie(0);
  int n;
  cin >> n;
  vector<tri> a;
  for(int i=1;i<=n;++i)
  {
    int w, s, v;
    cin >> w >> s >> v;
    a.emplace_back(w, s, v);
  }
  
  sort(a.begin(), a.end());
  
  for(int i=0;i<(int)a.size();++i)
  {
    for(int w=0;w<MAX*20+1;++w)
    {
      if(w <= a[i].s)
        dp[i+1][w+a[i].w] = max(dp[i+1][w+a[i].w], dp[i][w] + a[i].v);
      dp[i+1][w] = max(dp[i+1][w], dp[i][w]);
    }
  }
  
  ll ans = 0;
  for(int i=0;i<MAX*20+1;++i)
    ans = max(ans, dp[n][i]);
  cout << ans << endl;
  return 0;
}
