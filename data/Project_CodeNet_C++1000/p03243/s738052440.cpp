#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;
typedef long long ll;

int main() {
string S;
cin >> S;
if(S[0] == S[1] && S[1] == S[2]) { cout << S; return 0; }

for(char i = '1'; i <= '9'; i++) {
  if(S[0] == i) {
    if(S[1] < i) { cout << S[0] << S[0] << S[0]; return 0; }
    else if(S[1] > i) { cout << (S[0] - '0') + 1 << (S[0] - '0') + 1 << (S[0] - '0') + 1; return 0; }
    else if(S[1] == S[0]) {
      if(S[2] < S[1]) { cout << S[0] << S[0] << S[0]; return 0; }
      else { cout << (S[0] - '0') + 1 << (S[0] - '0') + 1 << (S[0] - '0') + 1; return 0; }
     }
  }
}
 return 0;
}