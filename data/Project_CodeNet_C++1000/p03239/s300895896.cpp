#include <bits/stdc++.h>
using namespace std;


int main() {
  int n, T; cin >> n >> T;
  int m = 10000;
  for(int i = 0; i < n; i++){
    int c, t;
    cin >> c >> t;
    if(t <= T && c < m){
      m = c;
    }
  }
  if(m == 10000) cout << "TLE" << endl;
  else cout << m << endl;

}
