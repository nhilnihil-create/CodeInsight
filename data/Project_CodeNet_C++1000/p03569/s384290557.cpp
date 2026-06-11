#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int N = s.size();
  string t;
  for (int i = 0; i < N; i++){
    if (s[i] != 'x'){
      t += s[i];
    }
  }
  string t2 = t;
  reverse(t2.begin(), t2.end());
  if (t != t2){
    cout << -1 << endl;
  } else {
    vector<int> cnt(1, 0);
    for (int i = 0; i < N; i++){
      if (s[i] == 'x'){
        cnt.back()++;
      } else {
        cnt.push_back(0);
      }
    }
    vector<int> cnt2 = cnt;
    reverse(cnt2.begin(), cnt2.end());
    int sz = cnt.size();
    int ans = 0;
    for (int i = 0; i < sz / 2; i++){
      ans += abs(cnt[i] - cnt2[i]);
    }
    cout << ans << endl;
  }
}