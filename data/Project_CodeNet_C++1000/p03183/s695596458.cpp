#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (n);i++)
#define sz(x) int(x.size())
typedef long long ll;
typedef pair<int,int> P;

ll dp[20100];

int main(){
  int n;
  cin >> n;
  vector<pair<P,int>> t(n);

  rep(i,n) {
    int w, s, v;
    cin >> w >> s >> v;
    t[i] = {{w,s},v};
  }
  sort(t.begin(), t.end(),[&](auto a, auto b) {
    return a.first.first + a.first.second < b.first.first + b.first.second;
  });

  for (int i = 0; i < n; i++) {
    for (int j = t[i].first.second; j >= 0; j--) {
      dp[j + t[i].first.first] = max(dp[j + t[i].first.first], dp[j] + t[i].second); 
    }
  }
  ll res = 0;
  for (int i = 0; i <= 20000; i++) {
    res = max(res, dp[i]);
  }
  cout << res << endl;
  return 0;
} 