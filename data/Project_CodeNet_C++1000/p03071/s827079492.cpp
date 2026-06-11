#include <bits/stdc++.h>
#define rep(i,s,n) for (int i = s; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int a,b;
  cin >> a >> b;
  if (a < b) {
    cout << 2*b-1 << endl;
  } else if (a == b) {
    cout << a+b << endl;
  } else {
    cout << 2*a - 1 << endl;
  }
  return 0;
}
