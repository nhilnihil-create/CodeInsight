#define _GIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;


int main(void) {
  string S;
  cin >> S;

  int not0101 = 0;   // 010101…と違う箇所の個数をカウント
  int not1010 = 0;

  rep(i, S.size()) {
    if (i % 2 == 0) {
      if (S[i] != '0') not0101++;
      else not1010++;
    } else {
      if (S[i] != '1') not0101++;
      else not1010++;
    }
  }

  int ans = not0101 < not1010 ? not0101 : not1010;
  cout << ans << endl;
  
  return 0;
}