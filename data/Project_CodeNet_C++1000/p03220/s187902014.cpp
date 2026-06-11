#include <bits/stdc++.h>
using namespace std;

int main(){
 
  int n; cin >> n;
  double T, A; cin >> T >> A ;
  double x;
  double y = 0.006;
  double ans = 1000000.0;
  int pos = -1;
  for(int i = 0; i < n; ++i){
     cin >> x;
     double temp = T - (x*y);
     if(ans > abs(temp - A) ){
       ans = abs(temp - A); pos = i + 1;
       //cout << ans << '\n';
     }
  }
  cout << pos << '\n';
}