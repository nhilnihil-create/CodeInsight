#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int64_t ans = 0;
  int64_t memo = 0;
  for (int i = 1; i < N; i++) {
    if (S.at(i) == 'E') {
      memo++;
      ans++;
    }
  }
  for (int i = 1; i < N; i++) {
    if (S.at(i) == 'E') {
      memo--;
    }    
    if (S.at(i - 1) == 'W') {
      memo++;
    }
    ans = min(ans, memo);
  }
  cout << ans << endl;          
}
          