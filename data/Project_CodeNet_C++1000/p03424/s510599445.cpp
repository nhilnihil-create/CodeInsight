#include <bits/stdc++.h>
using namespace std;

int main() {
  long N;
  cin >> N;
  string ans = "Three";
  char s;
  
  for (int i = 0; i < N; i++) {
    cin >> s;
    if (s == 'Y'){
      ans = "Four";
      break;
    }
  }
  
  cout << ans << endl;
}