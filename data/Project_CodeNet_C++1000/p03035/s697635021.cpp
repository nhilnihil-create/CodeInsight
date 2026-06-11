#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int a, b;
  cin >> a >> b;
  int ans = 0;
  if(a >= 13) ans = b;
  else if(6 <= a && a <= 12) ans = b/2;
  else if(a <= 5) ans = 0;
  
  cout << ans << endl;
}