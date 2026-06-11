#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,29)-1;


int main() {
  int N, K; cin >> N >> K;
  string result = ((N+1)/2>=K) ? "YES" : "NO";
  cout << result << endl;
  return 0;
}