#include <bits/stdc++.h>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  int N;
  cin >> N;
  vector<int> A(N);
  for(int i = 0; i < N; i++){
    cin >> A[i];
    A[i] -= i+1;
  }
  sort(A.begin(), A.end());
  int b = A[N/2];
  long long ans = 0;
  for(int i = 0; i < N; i++){
    ans += abs(A[i] - b);
  }
  cout << ans <<endl;
}
