#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;

signed main(){
  lint N, K; cin >> N >> K;
  string s; cin >> s;
  vector<lint> data;
  if(s[0] == '0') data.push_back(0);
  lint num = 1;
  for(int i = 0; i < s.size();) {
    int j = i;
    while (j < s.size() && s[j] == s[i]) ++j; 
    data.push_back(j - i);
    i = j;
  }
  if(s.back() == '0') data.push_back(0);
  lint ans1 = 0, ans;
  for(lint i = 0; i < 2 * K + 1 && i < data.size(); i++){
    ans1 += data[i];
  }
  ans = ans1;
  for(lint i = 2 * K + 2; i < data.size(); i += 2){
     ans1 = ans1 + data[i] + data[i - 1] - data[i - 2 * K - 1] - data[i - 2 * K - 2];
     ans = max(ans, ans1);
  }
  cout << ans << endl;
}
