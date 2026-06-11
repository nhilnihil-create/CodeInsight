#include <bits/stdc++.h>
using namespace std;

int main() {
  string S, T;
  cin >> S >> T;
  
  if (S[0] == T[2] && S[1] == T[1] && S[2] == T[0]) {
    cout << "YES" << endl;
  } else {
    cout << "NO" << endl;
  }
}