#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main(){
  int n;
  cin >> n;
  vector<double> x(n);
  vector<string> u(n);
  rep(i,n){
    cin >> x[i] >> u[i];
  }
  
  double y = 0;
  rep(i,n){
    if(u[i] == "JPY"){
      y += x[i];
    }
    if(u[i] == "BTC"){
      y += x[i] * 380000.0;
    }
  }
  cout << y << endl;
}