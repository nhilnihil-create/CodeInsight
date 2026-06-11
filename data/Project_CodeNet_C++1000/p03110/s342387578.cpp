#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<double> x(n);
  vector<string> u(n);
  for (int i=0 ; i<n ; i++)
    cin >> x.at(i) >> u.at(i);
  
  double ans = 0, plus;
  for (int i=0 ; i<n ; i++){
    if (u.at(i) == "JPY")
      ans += x.at(i);
    else
      ans += x.at(i) * 380000;
  }
  
  cout << fixed << setprecision(8) << ans << endl;
}