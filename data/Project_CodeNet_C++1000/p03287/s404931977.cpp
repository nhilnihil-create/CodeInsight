#include <bits/stdc++.h>
#define F first
#define S second
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  ll M;
  cin >> N >> M;
  ll A[N];
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  map<ll,int> mp;
  ll R[N+1];
  R[0] = 0;
  mp[0]++;
  ll ans = 0;
  for (int i = 0; i < N; i++) {
    R[i+1] = R[i] + A[i];
    R[i+1] %= M;
    ans += mp[R[i+1]];
    mp[R[i+1]]++;
  }
  cout << ans << endl;
  return 0;
}