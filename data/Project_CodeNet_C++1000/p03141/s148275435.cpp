#include <bits/stdc++.h>
using namespace std;
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
typedef pair<int, int> P;
int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  ll bl = 0;
  REP(i, N) {
    ll a, b;
    cin >> a >> b;
    A[i] = a + b;
    bl += b;
  }
  sort(A.begin(), A.end(), greater<ll>());
  ll ans = 0;
  REP(i, N) {if(i%2==0) ans += A[i]; }
  cout << ans - bl << endl;
}