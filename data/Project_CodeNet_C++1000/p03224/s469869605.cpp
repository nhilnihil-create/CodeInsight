#include<bits/stdc++.h>
#define rep(i,N) for(ll (i)=0;(i)<(N);(i)++)
#define chmax(x,y) x=max(x,y)
#define chmin(x,y) x=min(x,y)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int mod = 1000000007;
const int INF = 1001001001;

int main() {
  int n;
  cin >> n;
  ll nums = 1;
  bool ok = false;
  for (; nums * (nums - 1) / 2 <= n; ++nums) {
    if (nums * (nums - 1) / 2 == n) {
      ok = true;
      break;
    }
  }

  if (!ok) {
    cout << "No" << endl;
    return 0;
  }
  cout << "Yes" << endl;
  
  ll length = nums - 1;
  vector<vector<int>> ans(nums);
  int cur = 1;
  for (int i = 0; i < nums; ++i) {
    for (int j = i + 1; j < nums; ++j) {
      ans[i].push_back(cur);
      ans[j].push_back(cur);
      cur++;
    }
  }
  cout << nums << endl;
  rep(i, nums) {
    cout << ans[i].size() << " ";
    rep(j, ans[i].size()) printf("%lld%c", ans[i][j], (j == length - 1 ? '\n' : ' '));
  } 

}