//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define allr(v) v.rbegin(), v.rend()

int main() {
  string s;
  cin >> s;
  
  int mx = 0;
  vector<int> vec(s.size());
  rep(i, s.size()) {
    vec[i] = s[i] - '0';
    mx += s[i] - '0';
  }
  
  for(int i = 0; i <= s.size()-1; i++) {//i要素目を１つ下げてi+1以降は9
    if (vec[i] == 0) continue;
    int cnt = 0;
    for (int j = 0; j <= i; j++) {
      cnt += vec[j];
    }
    cnt--;
    cnt += 9*(s.size() - (i+1));
    mx = max(mx, cnt);
  }
  cout << mx << endl;
  return 0;
}