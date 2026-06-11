#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main()
{
  int n;
  cin >> n;
  
  long double x[n];
  string u[n];
  rep(i,n) cin >> x[i] >> u[i];
  
  long double ans = 0.0;
  rep(i,n){
    if(u[i] == "JPY"){
      ans += (long double)x[i];
    }else{
      ans += x[i] * 380000.0;
    }
  }
  
  cout << fixed;
  cout << setprecision(20);
  cout << ans << endl;
  
}