#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string s, t;
  cin >> s >> t;
  int S1 = s.size(), T1 = t.size();
  vector<char> S(S1), T(T1);
  for (int i = 0; i < S1; i++) {
    S.at(i) = s.at(i);    
  }
  for (int i = 0; i < T1; i++) {
    T.at(i) = t.at(i);
  }
  sort(S.begin(), S.end());
  sort(T.begin(), T.end());
  reverse(T.begin(), T.end());
  for (int i = 0; i < S1; i++) {
    s.at(i) = S.at(i);
  }
  for (int i = 0; i < T1; i++) {
    t.at(i) = T.at(i);
  }
  if (s < t) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}
    