#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, X;
  cin >> N >> X;
  vector <int> m(N);
  rep(i,N) cin >> m[i];

  int sum = accumulate(all(m), 0);
  X -= sum;  //全種類1個ずつ作ったあとの残り
  int num = X / *min_element(all(m));  //お菓子の素が最小のドーナツの個数
  int ans = N + num;
  cout << ans << endl;
}
