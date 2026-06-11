#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b;
  cin >> a >> b;
  int sum = 0;
  int sa = b - a;
  for(int i = 1; i <= sa; i++) sum += i;
  int ans = sum - b;
  
  cout << ans << endl;
  return 0;
}