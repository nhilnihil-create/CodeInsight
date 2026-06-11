#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
  int n,T;
  cin >> n >> T;
  int x = 10000;
  rep(i,n){
    int c,t;
    cin >> c >> t;
    if(t <= T && c < x) x = c; 
  }
  if(x == 10000) cout << "TLE" << endl;
  else cout << x << endl;
 }
