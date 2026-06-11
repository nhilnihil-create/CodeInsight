#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, c, x;
  cin >> a >> b >> c >> x;
  int cnt = 0;
  for(int i = 0; i <= a; i++) {
    for(int j = 0; j <= b; j++) {
      for(int k = 0; k <= c; k++) {
        int sum = 0;
        sum = 500*i + 100*j + 50*k;
        if(x == sum) cnt++;
      }
    }
  }
  cout << cnt << endl;
  return 0;
}