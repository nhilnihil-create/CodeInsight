#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  
  int ans = 0, sum = 0;
  for (int i = 0; i < S.size(); i++) {
    
    if (S.at(i) == 'A' || S.at(i) == 'C' || S.at(i) == 'G' || S.at(i) == 'T') {
      sum++;
    } else {
      sum = 0;
    }
    ans = max(ans, sum);
  }

  cout << ans << endl;
}