#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n, s = 0;
  string a, b, c;
  cin >> n >> a >> b >> c;
  rep(i, n){
    if (a[i] == b[i] && b[i] == c[i]) continue;
    else if(a[i] == b[i] || a[i] == c[i] || b[i] == c[i]) ++s;
    else s += 2;
  }
  cout << s << endl;
  return 0;
}