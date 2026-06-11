#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int count = 0;
  int L = 0;
  int R = 0;
  int LR = 0;
  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    int k = s.size();
    if (s[0] == 'B' && s[k-1] == 'A') LR++;
    else if (s[0] == 'B') L++;
    else if (s[k-1] == 'A') R++;
    for (int j = 0; j < k-1; j++) {
      if (s.substr(j,2) == "AB") {
        count += 1;
        j += 1;
      }
    }
  }
  
  if (LR > 0) {
    count += LR-1;
    if (L > 0) {
      count += 1;
      L--;
    }
    if (R > 0) {
      count += 1;
      R--;
    }
  }
  cout << count + max(min(L,R),0) << endl;
}