#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;


int main() {
  int n, T;
  cin >> n >> T;
  int minv = 10000;
  rep(i,n){
    int c, t;
    cin >> c >> t;
    if(t<=T){
      minv = min(c,minv);
    }
  }
  if(minv==10000) cout << "TLE" << endl;
  else cout << minv << endl;
  return 0;
}