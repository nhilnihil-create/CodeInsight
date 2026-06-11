#include <bits/stdc++.h>
using namespace std;

int main(){
  int n; cin >> n;
  int ma=0, mb=0, mc=0;
  
  for(int i=0; i<n; ++i){
    int a, b, c;
    cin >> a >> b >> c;
    int ta=ma, tb=mb, tc=mc;
    ma = max(tb, tc) + a;
    mb = max(tc, ta) + b;
    mc = max(ta, tb) + c;
  }
  
  cout << max({ma, mb, mc}) << endl;
  
  return 0;
}