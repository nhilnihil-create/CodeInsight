#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N;
  cin >> N;
  vector<int> A(N), B(N);
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];

  int64_t sum_A = 0, sum_B = 0;
  rep(i, N) sum_A += A[i];
  rep(i, N) sum_B += B[i];

  if(sum_A < sum_B){
    cout << -1 << endl;
    return 0;
  }

  vector<int> C;
  int64_t low = 0;
  int ans = 0;
  rep(i, N){
    if(A[i] < B[i]){
      low += B[i] - A[i];
      ans++;
    }
    else if(B[i] < A[i]){
      C.push_back(A[i] - B[i]);
    }
  }

  sort(C.begin(), C.end(), greater<int>());

  int i = 0;
  while(0 < low){
    low -= C[i++];
    ans++;
  }

  cout << ans << endl;

  return 0;
}
