#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
int main() {
  int A, B;
  cin >> A >> B;
  if(A % 2 == 0) {
    if(A / 2 >= B) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
  else {
    if((A + 1) / 2 >= B) {
      cout << "YES" << endl;
    }
    else {
      cout << "NO" << endl;
    }
  }
}