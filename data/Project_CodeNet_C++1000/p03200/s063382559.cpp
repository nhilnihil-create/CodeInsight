#include <bits/stdc++.h>
using namespace std;

int main(){
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  int64_t ans = 0, cnt = 0;
  for(int i = 0; i < s.size(); i++){
    if (s.at(i) == 'B'){
      ans += i - cnt;
      cnt++;
    }
  }
  cout << ans;
}
