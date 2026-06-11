#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int a, b, k;
  cin >> a >> b >> k;
  rep(i, k){
    if(i % 2 == 0){
      b += a/2;
      a /= 2;
    }
    else{
      a += b/2;
      b /= 2;
    }
  }
  cout << a << " " << b << endl;
  return 0;
}