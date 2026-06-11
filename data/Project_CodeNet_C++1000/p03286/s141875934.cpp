#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll N;
  cin >> N;
  if (N==0) {
    cout << 0 << endl;
    return 0;
  }
  vector<int> A(0);
  while (N != 0) {
    int n = A.size();
    if (N % (ll)(pow(2,n+1)) == (ll)(pow(2,n)) || N % (ll)(pow(2,n+1)) == (ll)(pow(2,n) - pow(2,n+1))) {
      A.push_back(1);
      N -= pow(-2,n);
    } else {
      A.push_back(0);
    }
  }
  reverse(A.begin(),A.end());
  for (int i = 0; i < A.size(); i++) {
    cout << A[i];
  }
  cout << endl;
  return 0;
}