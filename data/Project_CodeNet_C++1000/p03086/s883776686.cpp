#include <bits/stdc++.h>
using namespace std;

void chmax(int& a, int b) {
  if (a < b) a = b;
}

int main() {
  string S;
  cin >> S;
  S += 'B';
  
  int ans = 0;
  // i スタートとしてカウント
  for (int i = 0; i < S.size(); i++) {
    if (S[i] != 'A' && S[i] != 'C' 
        && S[i] != 'G' && S[i] != 'T') continue;
    
    int count = 1;
    for (int j = i+1; j < S.size(); j++) {
      if (S[j] == 'A' || S[j] == 'C' 
        || S[j] == 'G' || S[j] == 'T') {
        count++;
      } else {
        chmax(ans, count);
        break;
      }
    }
    
  }
  
  cout << ans << endl;
}