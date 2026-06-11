#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  string s;
  cin >> s;
  vector<int> n(4);
  rep(i,4) n[i] = s[i] - '0';
  rep(i,1<<3) {
    string ans;
    ans += s[0];
    int cnt = 0;
    cnt = n[0];
    rep(j,3) {
      if(i>>j & 1) {
        ans.push_back('+');
        ans.push_back(s[j+1]);
        cnt += n[j+1];
      }else{
        ans.push_back('-');
        ans.push_back(s[j+1]);
        cnt -= n[j+1];
      }
    }
    if(cnt != 7) continue;
    cout << ans << "=7" << endl;
    return 0;
  }
  return 0;
}