#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n;
  cin >> n;
  vector<long double> x(n);
  vector<string> u(n);
  long double ans = 0;
  rep(i,n){
    cin >> x[i] >> u[i];
    if(u[i] == "BTC") x[i] *= 380000.0;
    ans += x[i];
  }
  cout << ans << endl;
}
