#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  string S;
  cin >> S;
  vector <int> cnt(2, 0);
  rep(i,S.length()){
     cnt[S[i] - '0'] ++;
  }
  int ans = 2 * min(cnt[0], cnt[1]);
  cout << ans << endl;
  return 0;
}
