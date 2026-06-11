#include <bits/stdc++.h>
using namespace std;

bool solve(string S) {
  if (S[0] != 'A') return false;
  int N = S.size();
  int con = 0;
  for (int i = 0; i < N; ++i) if (S[i] >= 'A' && S[i] <= 'Z') ++con;
  if (con != 2) return false;
  bool exist = false;
  for (int i = 2; i+1 < N; ++i) if (S[i] == 'C') exist = true;
  if (!exist) return false;
  
  return true;
}

int main() {
  string S;
  cin >> S;
  if (solve(S)) cout << "AC" << endl;
  else cout << "WA" << endl;
}
  
  