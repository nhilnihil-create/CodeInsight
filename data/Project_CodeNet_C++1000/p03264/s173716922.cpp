#include <bits/stdc++.h>
using namespace std;

int main() {
  int K;
  cin >> K;

  int odd = (K-1)/2 + 1;
  int even = K/2;

  cout << odd * even << endl;

  return 0;
}