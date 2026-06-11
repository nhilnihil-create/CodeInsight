#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int A, B, C, a, b, c;
  long long K;
  cin >> A >> B >> C >> K;
  if(K%2==0) cout << A-B << endl;
  else cout << B-A << endl;
}