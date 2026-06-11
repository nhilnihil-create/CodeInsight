#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  //input
  int N;
  cin >> N;
  vector <double> x(N);
  vector <string> u(N);
  rep(i,N) cin >> x[i] >> u[i];
  double rate = 380000.0;

  //solve
  double ans = 0;
  rep(i,N){
    if (u[i] == "BTC") ans += rate * x[i];
    else ans += x[i];
  }
  cout << fixed << setprecision(10) << ans << endl;
}
