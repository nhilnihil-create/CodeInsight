#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  string A;
  cin >> A;
  int N = A.size();
  int MI = 10000;
  rep(i, N - 2) {
    MI = min(abs((A.at(i) - '7') * 100 + (A.at(i+1) - '5') * 10 + A.at(i+2) - '3'), MI);
  }
  cout << MI << endl;
}