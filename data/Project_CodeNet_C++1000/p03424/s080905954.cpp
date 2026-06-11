#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  string s;
  string ans = "Three";
  cin >> N;
  
  for (int i = 0; i < N; i++) {
    cin >> s;
    if (s == "Y") {
      ans = "Four";
      break;
    } 
  }
  
  cout << ans << endl;
}