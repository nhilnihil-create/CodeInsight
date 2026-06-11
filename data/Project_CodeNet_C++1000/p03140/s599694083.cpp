#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N; cin >> N;
  string A, B, C; cin >> A >> B >> C;
  int result = 0;
  rep(i,N) {
    bool ab = A[i]==B[i], bc = B[i]==C[i], ca = C[i]==A[i];
    if (!ab&&!bc&&!ca) result += 2;
    else if (ab&&bc) continue;
    else result += 1;
  }
  cout << result << endl;
  return 0;
}