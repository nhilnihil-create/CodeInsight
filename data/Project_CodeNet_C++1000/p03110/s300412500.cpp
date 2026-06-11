 #include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >>N;
  vector<double> x(N);
  vector<string> u(N);
  for(int i = 0; i < N; ++i){
    cin >> x[i] >> u[i];
  }
  double ans = 0;
  for(int i = 0; i < N; ++i){
    if(u[i] == "BTC"){
      x[i] *= 380000.0;
      ans += x[i];
    } else {
      ans += x[i];
    }
  }
  cout << ans << endl;
}

