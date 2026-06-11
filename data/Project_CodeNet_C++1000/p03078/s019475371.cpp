#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;

int main() {
  int X, Y, Z, K;
  cin >> X >> Y >> Z >> K;
  vector<ll> A(X);
  vector<ll> B(Y);
  vector<ll> C(Z);
  rep(i,X) cin >> A[i];
  rep(i,Y) cin >> B[i];
  rep(i,Z) cin >> C[i];
  vector<ll> AB;
  rep(i,X) rep(j,Y) AB.push_back(A[i]+B[j]);
  sort(AB.rbegin(), AB.rend());
  vector<ll> AB_cand;
  ll k = min((int)AB.size(), K);
  rep(i,k) AB_cand.push_back(AB[i]);
  vector<ll> ans;
  rep(i,k) rep(j,Z) ans.push_back(AB_cand[i]+C[j]);
  sort(ans.rbegin(), ans.rend());
  rep(i, K) cout << ans[i] << endl;
}