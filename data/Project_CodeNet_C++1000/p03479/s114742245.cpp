#include <bits/stdc++.h>
using namespace std;

long long X, Y, i;

int main() {
  cin >> X >> Y;
  
  int ans = 0;
  do {
    ans++;
    X = X * 2;
  } while ( X <= Y );
  
  cout << ans << endl;
  
  return 0;
}