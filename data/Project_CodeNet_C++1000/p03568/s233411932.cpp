#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)n; i++)

int main() {
  int n;
  cin >> n;
  int ans = 1;
  int res = 1;
  rep(i,n) {
    ans *= 3;
    int a;
    cin >> a;
    if(a % 2 == 0) res *= 2; 
  }
  cout << ans - res << endl;
  return 0;
}