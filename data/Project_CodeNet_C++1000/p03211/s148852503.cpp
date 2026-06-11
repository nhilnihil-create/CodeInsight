#include <bits/stdc++.h>
using namespace std;

void chmin (int& a, int b) {
  if (a > b) a = b;
}
int main() {
  string S;
  cin >> S;
  
  int ans = 999;
  for (int i = 0; i < S.size()-2; i++) {
    if (S[i] > '7') {
      chmin(ans, (S[i]-'7') * 100 + (S[i+1]-'5') * 10 + S[i+2]-'3');
    } else if (S[i] < '7') {
      chmin(ans, ('7'- S[i]) * 100 + ('5'-S[i+1]) * 10 + '3'-S[i+2]);
    } else {
      if (S[i+1] > '5') {
        chmin(ans, (S[i]-'7') * 100 + (S[i+1]-'5') * 10 + S[i+2]-'3');
      } else if (S[i+1] < '5') {
        chmin(ans, ('7'- S[i]) * 100 + ('5'-S[i+1]) * 10 + '3'-S[i+2]);
      } else {
        if (S[i+2] >= '3') {
          chmin(ans, (S[i]-'7') * 100 + (S[i+1]-'5') * 10 + S[i+2]-'3'); 
        } else {
          chmin(ans, (S[i]-'7') * 100 + (S[i+1]-'5') * 10 + '3'-S[i+2]);
        }
      }
    }
  }
  
  cout << ans << endl;

}