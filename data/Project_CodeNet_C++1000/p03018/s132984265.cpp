#include <bits/stdc++.h>
using namespace std;
int main(){
  string s;
  cin >> s;
  int N = s.size();
  string t;
  t += s[0];
  for (int i = 1; i < N; i++){
    if (t.back() == 'B' && s[i] == 'C'){
      t.pop_back();
      t += 'X';
    } else {
      t += s[i];
    }
  }
  int M = t.size();
  long long ans = 0;
  int cnt = 0;
  for (int i = 0; i < M; i++){
    if (t[i] == 'A'){
      cnt++;
    } else if (t[i] == 'X'){
      ans += cnt;
    } else {
      cnt = 0;
    }
  }
  cout << ans << endl;
}