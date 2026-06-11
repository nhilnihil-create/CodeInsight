#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
using namespace std;

int main() {
  int N; cin >> N;

  vector<double> x( N, 0.0 );
  vector<string> u( N, "" );
  rep( i, 0, N ) cin >> x.at(i) >> u.at(i);

  double Ans = 0.0;

  rep( i, 0, N ) {
    if ( u.at(i) == "JPY" ) Ans += x.at(i);
    else Ans += 380000.0*x.at(i);
  }

  cout << Ans << endl;
}
