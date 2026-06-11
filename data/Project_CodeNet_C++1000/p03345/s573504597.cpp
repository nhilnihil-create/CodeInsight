#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
  ll A, B, C, K;
  cin >> A >> B >> C >> K;
  if(K % 2 == 0) {
    cout << A - B << endl;
  }
  else {
    cout << B - A << endl;
  }
}