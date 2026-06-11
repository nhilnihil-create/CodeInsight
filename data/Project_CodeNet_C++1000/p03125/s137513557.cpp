#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int A, B;
  cin >> A >> B;
  if(B % A == 0){
    cout << A + B <<endl;
  } else {
    cout << B - A <<endl;
  }
}
