#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n, h, w, s = 0;
  cin >> n >> h >> w;
  rep(i, n){
    int a, b;
    cin >> a >> b;
    if(a >= h && b >= w) ++s;
  }
  cout << s << endl;
  return 0;
}