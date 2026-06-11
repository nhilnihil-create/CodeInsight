#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n, b, c = 100000000, r;
  cin >> n;
  long double a = 0.0, tmp = 10000;
  vector<int> v(n);
  rep(i, n){
    cin >> v[i];
    a += v[i];
  }
  a /= n;
  rep(i, n){
    if(tmp > abs(a-v[i])){
      tmp = abs(a-v[i]);
      r = i;
    }
  }
  cout << r << endl;
  return 0;
}