#include<iostream>
#include <string>
#include <vector>
#include <cmath>
#include <algorithm>
#include <map>
#include <queue>
#define rep(i,n) for (ll i = 0; i < (n); ++i)
#define all(x) (x).begin(), (x).end()
#define P_B push_back
#define PO_B pop_back
#define E_B emplace_back
#define fi first
#define se second
#define debug(x) cout << #x << ": " << x << endl

using namespace std;
using ll = long long;
using Pii = pair<int,int>;
using Pll = pair<ll,ll>;
using VI = vector<int>;
using VL = vector<ll>;
using VVI = vector<vector<int> >;
using VVL = vector<vector<ll> >;
//int dx[4] = {1, 0, -1, 0};
//int dy[4] = {0, 1, 0, -1};
const ll LINF = (ll)1e18 - 1;
//const int INF = 1e9 - 1;

bool judge(VL &s, VL &h, ll x) {
  int n = s.size();
  VL t(n);
  rep(i, n) {
    if (x < h[i]) return false;
    t[i] = (x - h[i]) / s[i];
  }
  sort(all(t));
  rep(i, n) {
    if (t[i] < i) return false;
  }
  return true;
}


int main(){
  ll N, ans;
  cin >> N;
  vector<ll> A(N), B(N), C(N), ab(N+1), bcsum(N+1);

  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  rep(i, N) cin >> C[i];

  sort(all(A));
  sort(all(B));
  sort(all(C));

  ab[N] = 0;
  bcsum[N] = 0;
  for(int i = N-1; i >= 0; i--){
    bcsum[i] = N - distance(C.begin(), upper_bound(C.begin(), C.end(), B[i])) + bcsum[i+1];
  }

  ans = 0;
  rep(i, N){
    ans += bcsum[distance(B.begin(), upper_bound(B.begin(), B.end(), A[i]))];
  }

  cout << ans << endl;


  return 0;
}
