#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint MOD = 1e9+7;

signed main(){
  lint N; cin >> N;
  string s; cin >> s;
  vector<lint> num(26, 0);
  for(lint i = 0; i < N; i++) num[s[i] - 'a']++;
  lint ans = 1;
  for(lint i = 0; i < 26; i++){
    ans *= (num[i] + 1);
    ans %= MOD;
  }
  cout << ans-1 << endl;
}