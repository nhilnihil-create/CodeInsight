#include <bits/stdc++.h>
#include<chrono>
using namespace std;
using ll = long long;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  if (S == "keyence") {
    cout << "YES"<< endl;
    return 0;
  }
  if (N == 7) {
    cout << "NO" << endl;
  }
  //iは除く文字列の最初の位置
  for (int i = 0; i <= 6; i++) {
    string s = S;
    string Sn = s.erase(i, N-7);
    if (Sn == "keyence") {
      cout << "YES" << endl;
      return 0;
    }
  }
  cout << "NO" << endl;
}