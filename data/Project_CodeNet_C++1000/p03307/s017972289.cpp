#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int n;
  cin >> n;
  if(n == 1) cout << 2 << endl;
  else if(n % 2 == 0) cout << n << endl;
  else if(n % 2 != 0) cout << n * 2 << endl;
  return 0;
}