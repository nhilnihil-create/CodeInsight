#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int a, b;
  cin >> a >>b;
  int sum = 0;
  rep(i, 2) {
    if(a > b) {
      sum += a;
      a--;
    }
    else {
      sum += b;
      b--;
    }
  }
  
  cout << sum << endl;
}
      