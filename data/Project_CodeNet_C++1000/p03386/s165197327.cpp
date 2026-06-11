#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  for(int i = a; i <= min(a+k-1, b); i++) {
    cout << i << endl;
  }
  for(int i = max(b-k+1, a+k); i <= b; i++) {
    cout << i << endl;
  }
  return 0;
}