#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N, Q;
  string S;
  cin >>  N >> Q >> S;
  vector <int> l(Q), r(Q);
  rep(i,Q) cin >> l[i] >> r[i];
  vector <int> sum(N + 1);
  //一つ左にずらした累積和
  for (int i = 1; i < N; i++){
    if (S[i - 1] == 'A' && S[i] == 'C'){
      sum[i + 1] = sum[i] + 1;
    }else{
      sum[i + 1] = sum[i];
    }
  }
  rep(i,Q){
    int ans = sum[r[i]] - sum[l[i]];
    cout << ans << endl;
  }
  return 0;
}
