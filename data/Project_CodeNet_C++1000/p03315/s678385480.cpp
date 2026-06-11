#include<bits/stdc++.h>
using namespace std;
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;


int main() {
  vector<char> S(4);
  int ans = 0;
  rep(i,4) cin >> S[i];
  rep(i,4) {
    if(S[i] == '+'){
      ans++;
    } else {
      ans--;
    }
  }
  cout << ans << endl;
  return 0;
}
