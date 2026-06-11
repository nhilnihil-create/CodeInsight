#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  string S;
  cin >> S;
  if((S[0] == S[1] && S[1] == S[2]) ||( S[1] == S[2] && S[2] == S[3])) cout << "Yes" <<endl;
  else cout << "No" <<endl;
} 
