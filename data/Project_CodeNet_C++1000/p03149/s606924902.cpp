#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N[4]; rep(i,4) cin >> N[i];
  sort(N,N+4);
  string result = (N[0]==1&&N[1]==4&&N[2]==7&&N[3]==9) ? "YES" : "NO";
  cout << result << endl;
  return 0;
}