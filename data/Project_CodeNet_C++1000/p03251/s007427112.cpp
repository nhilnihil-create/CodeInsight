#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  //input
  int N, M, X, Y;
  cin >> N >> M >> X >> Y;
  vector <int> x(N);
  vector <int> y(M);
  rep(i,N) cin >> x[i];
  rep(i,M) cin >> y[i];

  //solve
  string ans = "War";
  for (int i = X + 1; i <= Y; i++){
    if (i > *max_element(all(x)) && i <= *min_element(all(y)) ){
      ans = "No War";
      break;
    }
  }
  cout << ans << endl;
}
