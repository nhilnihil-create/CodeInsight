#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const ll MOD = 1000000007;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  REP(i, N) cin >> A[i];
  vector<int> B(N+10);
  REP(i, N) { B[A[i]] = B[A[i] - 1] + 1; }
  cout << N - *max_element(B.begin(), B.end()) << endl;
}