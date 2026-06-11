#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N), B(N), memo(N); // memoには，A_i+B_iの値を格納
  for (int i=0; i<N; i++) {
    cin >> A[i] >> B[i];
    memo[i] = A[i]+B[i];
  }
  sort(memo.begin(), memo.end());
  reverse(memo.begin(), memo.end());
  ll ans = 0LL;
  for (int i=0; i<N; i+=2) ans += memo[i];
  ans -= accumulate(B.begin(), B.end(), 0LL);
  cout << ans << endl;
}