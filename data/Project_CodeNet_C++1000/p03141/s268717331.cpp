#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main () {
  int N;
  cin >> N;
  vector<ll>A(N);
  vector<ll>B(N);
  vector<pair<ll, int>>C(N);
  for (int i = 0; i < N; i ++) {
    cin >> A[i] >> B[i];
    C[i] = make_pair(A[i] + B[i], i);
  }
  sort(C.begin(), C.end());
  ll ans = 0;
  for (int i = 0; i < N; i ++) {
    int k = N - i - 1;
    int j = C[k].second;
    if (i % 2 == 0) {
      ans += A[j];
    }
    else {
      ans -= B[j];
    }
  }
  cout << ans << endl;
}