#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int ans = 0;
  int count = 0;
  for(int i = 0; i < S.size(); i++) {
    if(S[i] == 'A' || S[i] == 'C' || S[i] == 'G' || S[i] == 'T') {
      count++;
    }
    else {
      count = 0;
      continue;
    }
    ans = max(ans, count);
  }
  cout << ans << endl;
}