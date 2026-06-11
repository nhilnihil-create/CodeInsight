#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
const long long INF = 1LL << 60;
const ll MOD = 1000000007;
using pint = pair<ll, ll>;

int main() {
  ll N, M;
  ll a, b;
  cin >> a >> b;
  N = min(a, b);
  M = max(a, b);
  if (N == 1 && M == 1) {
    cout << 1 << endl;
  }
  else if(N-2>=0 && M-2>=0){
    cout << (N-2) * (M - 2) << endl;
  }
  else if(N-2>=0 || M-2>=0){
    cout << max(N-2, M-2) << endl;
  }
  else{
    cout << 0 << endl;
  }

  return 0;
}