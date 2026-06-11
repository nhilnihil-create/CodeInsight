#include <bits/stdc++.h>
using namespace std;

int main() {
  string S;
  cin >> S;
  int b = 0;
  int N = S.size();
  if (S.substr(0,7) == "keyence" || S.substr(N-7) == "keyence") b = 1;
  if (S.substr(0,6) == "keyenc" && S.substr(N-1) == "e") b = 1;
  if (S.substr(0,5) == "keyen" && S.substr(N-2) == "ce") b = 1;
  if (S.substr(0,4) == "keye" && S.substr(N-3) == "nce") b = 1;
  if (S.substr(0,3) == "key" && S.substr(N-4) == "ence") b = 1;
  if (S.substr(0,2) == "ke" && S.substr(N-5) == "yence") b = 1;
  if (S.substr(0,1) == "k" && S.substr(N-6) == "eyence") b = 1;
  
  if (b) {
    cout << "YES" << endl;
    return 0;
  }
  cout << "NO" << endl;
}