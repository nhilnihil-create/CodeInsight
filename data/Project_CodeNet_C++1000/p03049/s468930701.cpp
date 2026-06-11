#include <bits/stdc++.h>

using namespace std;

int main(void) {
  int N;
  cin >> N;
  
  int cnt = 0, a_cnt = 0, b_cnt = 0, double_cnt = 0;
  string s;
  for (int i = 0;i < N;i++) {
    cin >> s;
    
    for (int j = 0;j < s.length()-1;j++) {
      if (s[j] == 'A') {
        if (s[j+1] == 'B') cnt++;
      }
    }
    
    if (s[0] == 'B') b_cnt++;
    if (s[s.length() - 1] == 'A') a_cnt++;
    if (s[0] == 'B' && s[s.length() - 1] == 'A') double_cnt++;
  }
  
  if (double_cnt == a_cnt && a_cnt == b_cnt) {
    a_cnt = max(0, a_cnt-1);
    b_cnt = max(0, b_cnt-1);
  }
  cout << cnt + min(a_cnt, b_cnt) << endl;

}
