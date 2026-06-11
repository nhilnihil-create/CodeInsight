#include <bits/stdc++.h>
using namespace std;
using lint = long long;
const lint INF = 1e18;

signed main(){
  lint N, K; cin >> N >> K;
  string s; cin >> s;
  vector<lint> data;
  if(s[0] == '0') data.push_back(0);
  for(lint i = 0; i < s.size();) {
    lint j = i;
    while (j < s.size() && s[j] == s[i]) ++j; 
    data.push_back(j - i);
    i = j;
  }
  if(s.back() == '0') data.push_back(0);
  vector<lint> sum(data.size() + 1, 0);
  for(lint i = 0; i < data.size(); i++) sum[i + 1] = sum[i] + data[i];
  lint ans = 0;
  for(lint left = 0; left < sum.size(); left += 2){
    lint right = left + 2 * K + 1;
    right = min(right, lint(sum.size() - 1));
    ans = max(ans, sum[right] - sum[left]);
  }
  cout << ans << endl;
}