#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  vector <int> V(N);
  vector <int> C(N);
  rep(i,N) cin >> V[i];
  rep(i,N) cin >> C[i];

  vector <int> X(N);  //V_i - C_i 価値とコストの差
  rep(i,N) X[i] = V[i] - C[i];

  int ans = 0;
  rep(i,N){
    if (X[i] > 0) ans += X[i];
  }
  cout << ans << endl;
}
