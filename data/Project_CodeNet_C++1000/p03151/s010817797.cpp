#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll mod = 998244353;
const int MAX = 510000;

int main() {
  ll N;
  cin >> N;
  vector<ll> A(N), B(N);
  for (ll i=0; i<N; i++) cin >> A[i];
  for (ll i=0; i<N; i++) cin >> B[i];
  // A[i]<B[i]なるiが存在するかどうか
  bool exist = false;
  for (ll i=0; i<N; i++) {
    if (A[i]<B[i]) {
      exist = true;
      break;
    }
  }
  if (!exist) cout << 0 << endl;
  else {
    ll S = 0, res = 0;
    vector<ll> C(N); // A[i]-B[i]を格納
    for (ll i=0; i<N; i++) {
      if (A[i]<B[i]) {
        S += B[i]-A[i];
        res++;
      }
      else C.push_back(A[i]-B[i]);
    }
    sort(C.begin(), C.end());
    reverse(C.begin(), C.end());
    ll sum = 0;
    for (ll i=0; i<C.size(); i++) {
      sum += C[i];
      if (sum<S&&i==C.size()-1) {
        cout << -1 << endl;
        break;
      }
      else if (sum>=S) {
        cout << res+i+1 << endl;
        break;
      }
    }
  }
}