#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int n, m; // 人数, 種類
  cin >> n >> m;
  vector<int> cnt(m, 0);
  for(int j = 0; j < n; j++){
    int k; cin >> k;
  	rep(i, k){
      int a; cin >> a;
      a--;
      cnt[a]++;
    }
  }
  int ans = 0;
  rep(i, m){
  	if(cnt[i] == n){
    	ans++;
    }
  }
  cout << ans << endl;
  return 0;
}