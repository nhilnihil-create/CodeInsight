#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  S.at(K - 1) += 'a' - 'A';
  cout << S << endl;
}
