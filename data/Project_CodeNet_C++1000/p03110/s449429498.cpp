#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, n) for (int i = 1; i <= (int)(n); i++)

int main(){
  int N;

  cin >> N;
   cout << fixed << setprecision(5) << endl;
  vector<double> x(N);
  vector<string> u(N);

  for (int i = 0; i < N; i++){
    cin >> x.at(i);
    cin >> u.at(i);
  }

  double jpy = 1;
  double btc = 380000.0;

  double sum = 0;

  for (int i = 0; i < N; i++){
    if (u.at(i) == "JPY"){
      sum += x.at(i) * jpy;
    }
    else if (u.at(i) == "BTC")
    {
      sum += x.at(i) * btc;
    }
    
  }

  cout << sum << endl;
}