#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  int k;
  cin >> k;
  int cnt_even = 0;
  int cnt_odd = 0;
  
  for(int i = 1; i <= k; i++) {
    if(i % 2 == 0) cnt_even++;
    else cnt_odd++;
  }
  
  int ans = cnt_even * cnt_odd;
  
  cout << ans << endl;
}