#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < n; ++i)
using namespace std;

int main() {
  int n, m = 0;
  cin >> n;
  vector<int> v(n);
  rep(i, n) cin >> v[i];
  rep(i, n-1){
    if(v[i] == v[i+1]){
      ++m;
      v[i+1] = 0;
    }
  }
  cout << m << endl;
  return 0;
}
