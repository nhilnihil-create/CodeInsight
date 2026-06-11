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
  REP(i, N) { cin >> A[i]; }
  sort(A.begin(), A.end(), greater<int>());
  int a = 0, b = 0;
  REP(i, N) {
    if (i % 2 == 0)
      a += A[i];
    else
      b += A[i];
  }
  cout << a - b << endl;
}