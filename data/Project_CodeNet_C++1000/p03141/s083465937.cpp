#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<ll, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  ll A[N],B[N];
  for (int i = 0; i < N; i++) cin >> A[i] >> B[i];
  vector<P> Q;
  for (int i = 0; i < N; i++) {
    Q.push_back(make_pair(A[i]+B[i],i));
  }
  sort(Q.begin(),Q.end());
  reverse(Q.begin(),Q.end());
  ll Asum = 0;
  ll Bsum = 0;
  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      Asum += A[Q[i].second];
    } else {
      Bsum += B[Q[i].second];
    }
  }
  cout << Asum - Bsum << endl;
  return 0;
}