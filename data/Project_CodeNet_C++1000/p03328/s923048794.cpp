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
  int ans = ((b-a)*(b-a+1))/2 - b;
  cout << ans << endl;
  return 0;
}