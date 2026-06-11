#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  int a = 0, b = 0, ab = 0;
  int ans = 0;
  for (int i = 0; i < N; i++) {
    string S;
    cin >> S;
    
    if (S[0] == 'B') {
      if (S[S.size()-1] == 'A') {
        ab++;
      } else {
        b++;
      }
    }
    if (S[S.size()-1] == 'A' && S[0] != 'B') {
      a++;
    }
    
    for (int j = 0; j < S.size()-1; j++) {
      if (S[j] == 'A' && S[j+1] == 'B') ans++;
    }
    
  }
  
  if (ab == 0) {
    ans += min(a, b);
  } else {
    if (a + b > 0) {
      ans += ab + min(a, b);
    } else {
      ans += ab - 1;
    }
  }
  
  cout << ans << endl;
                 
  
}