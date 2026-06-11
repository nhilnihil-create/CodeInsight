#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
#define p_ll pair<ll, ll>
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  string S; cin >> S;
  int w; cin >> w;
  string result;
  for (int i=0; i<S.length(); i+=w) result += S[i];
  cout << result << endl;
  return 0;
}