#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N;
  cin >> N;
  vector <int> p(N);
  rep(i,N) cin >> p[i];

  int mx = *max_element(all(p));
  int ans = mx / 2 + (accumulate(all(p), 0) - mx) ;
  cout << ans << endl;
}
