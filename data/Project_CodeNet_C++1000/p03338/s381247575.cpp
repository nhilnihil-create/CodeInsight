#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 0;
  for (int i = 1; i < N - 1; i++) {
    vector<char> S1(i), S2(N - i);
    int k = 0;
    int k2 = 0;
    int memo = 0;
    for (int j = 0; j < N; j++) {
      if (j < i) {
        S1.at(k) = S.at(j);
        k++;
      }
      else {
        S2.at(k2) = S.at(j);
        k2++;
      }
    }
    sort(S1.begin(), S1.end());
    sort(S2.begin(), S2.end());
    for (int j = 0; j < i - 1; j++) {
      if (S1.at(j) == S1.at(j + 1)) {
        S1.at(j) = '#';
      }
    }
    for (int j = 0; j < N - i - 1; j++) {
      if (S2.at(j) == S2.at(j + 1)) {
        S2.at(j) = '&';
      }
    }
    for (int j = 0; j < i; j++) {
       for (int v = 0; v < N - i; v++) {
         if (S1.at(j) == S2.at(v)) {
           memo++;
         }
       }
    }
    ans = max(ans, memo);
  }
  cout << ans << endl;
}
          