#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  double ans = 0;
  for(int i = 0; i < n; i++){
    double a; string s; cin >> a >> s;
    if(s == "BTC") ans += a * 380000.0;
    else ans += a;
  }
  cout << ans << endl;
}