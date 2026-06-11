#include <bits/stdc++.h>
using namespace std;
int main() {
  string S;
  cin >> S;
  int ans = 0;
  for(int i = 0; i < S.size(); i++) {
    int count = 0;
    for(int j = i; j < S.size(); j++) {
      if(S.at(j) == 'A' || S.at(j) == 'C' || S.at(j) == 'G' || S.at(j) == 'T') {
        count++;
      }
      else {
        break;
      }
    }
    if(count > ans) {
      ans = count;
    }
  }
  cout << ans << endl;
}