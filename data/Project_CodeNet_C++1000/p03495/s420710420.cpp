#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, K;
  cin >> N >> K;
  map<int,int> mp;
  rep(i, N) {
    int a;
    cin >> a;
    mp[a]++;
  }
  if((int)mp.size() <= K) {
    cout << 0 << endl;
    return 0;
  }
  vector<P> ans;
  for (auto a : mp){
    ans.push_back(P(a.second,a.first));
  }
  sort(ans.begin(), ans.end());
  int ball = 0;
  int yobun = (int)ans.size() - K;
  rep(i, yobun) ball += ans[i].first;
  cout << ball << endl;
  return 0;
}