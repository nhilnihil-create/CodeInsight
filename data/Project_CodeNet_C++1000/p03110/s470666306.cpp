#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int n;
  cin >> n;
  
  double x;
  string u;
  double goukei = 0;
  
  for ( int i = 0; i < n ; i++){
    cin >> x >> u;
    if ( u == "JPY" ){
      goukei += x;
    }else{
      goukei += x * 380000;
    }
  }
  
  cout << fixed << setprecision(7) << goukei << endl;
  
}