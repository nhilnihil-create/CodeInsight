#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  if(n % 2 != 0) {
    cout << "Hello World" << endl;
  }
  else {
    int a, b;
    cin >> a >> b;
    int ans = a + b;
    cout << ans << endl;
  }
  return 0;
}