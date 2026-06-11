#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define rep(i, n) for(int (i)=0;(i)<(n);(i)++)
#define chmin(x, y) x = min(x, y)
#define chmax(x, y) x = max(x, y)
int main() {
  string s;
  cin >> s;
  int n = s.size();
  ll res = 0;
  int start = -1;
  vector<string> ans;
  for(int i=0;i<n;i++) {
    if(s[i] == 'A') {
      if(start == -1) start = i;
      else continue;
    }
    else if(s[i] == 'B') {
      if(start == -1) continue;
      else if(i == n-1) {
        ans.emplace_back(s.substr(start, i-start));
        start = -1;
      }
      else if(s[i+1] == 'C') i++;
      else {
        ans.emplace_back(s.substr(start, i-start));
        start = -1;
      }
    }
    else if(s[i] == 'C') {
      if(start == -1) continue;
      else {
        ans.emplace_back(s.substr(start, i-start));
        start = -1;
      }
    }
  }
  if(start != -1) {
    ans.emplace_back(s.substr(start, n-start));
    start = -1;
  }
  for(int i=0;i<ans.size();i++) {
    string ss = ans[i];
    int bcNum = 0;
    for(auto it=ss.rbegin();it!=ss.rend();it++) {
      if(*it == 'C') {
        bcNum++;
        it++;
      }
      else if(*it == 'A') res += bcNum;
    }
  }

  cout << res << endl;
  return 0;
}
