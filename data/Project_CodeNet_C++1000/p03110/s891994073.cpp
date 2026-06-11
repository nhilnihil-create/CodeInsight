#include <bits/stdc++.h>
using namespace std;
#define rep(i,n); for(int i = 0;i<n;++i)
using ll = long long;
using P = pair<int,int>;

int main(){
  int n;
  cin >> n;
  double ans = 0;
  vector<double> x(n+10);
  vector<string> y(n+10);
  rep(i,n){
    cin >> x[i] >> y[i];
    if(y[i] == "JPY"){
      ans += x[i];
    }
    else{
      ans += x[i] * 380000;
    }
  }
  cout << setprecision(16) << ans << endl;
  return 0;
}
