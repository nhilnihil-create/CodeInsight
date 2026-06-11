#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;
  vector<double> x(n);
  vector<string> u(n);
  rep(i,n){
    cin >> x[i] >> u[i];
  }
  
  double ans;
  rep(i,n){
    if(u[i]=="JPY"){
      ans += x[i];
    }else{
      ans += x[i]*380000.0;
    }
  }
  cout << ans << endl;
}
