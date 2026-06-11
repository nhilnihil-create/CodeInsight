#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int d, n; cin >> d >> n;
  if(d == 0) cout << (n < 100 ? n : 101) << '\n';
  else if(d == 1) cout << (n < 100 ? n*100 : 10100) << '\n';
  else cout << (n < 100 ? n*10000 : 1010000) << '\n';
}