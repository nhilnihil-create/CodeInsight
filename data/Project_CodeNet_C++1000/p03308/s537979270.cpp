#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int inf{int(1e9)};
int main(void){
  int N;
  cin >> N;
  vector <int> A(N);
  rep(i,N) cin >> A[i];

  int ans = 0;
  for (int i = 0; i < N; i++){
    for (int j = i + 1; j < N; j++){
      ans = max(ans, abs(A[i] - A[j]));
    }
  }
  cout << ans << endl;
}
