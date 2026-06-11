#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  ll X,Y,Z,K;
  cin >> X >> Y >> Z >> K;
  vector<ll> A(X);
  vector<ll> B(Y);
  vector<ll> C(Z);
  vector<ll> D;
  for (int i = 0; i < X; i++) {
    cin >> A[i];
  }
  for (int i = 0; i < Y; i++) {
    cin >> B[i];
  }
  for (int i = 0; i < Z; i++) {
    cin >> C[i];
  }
  sort(A.begin(),A.end(), greater<ll>());
  sort(B.begin(),B.end(), greater<ll>());
  sort(C.begin(),C.end(), greater<ll>());
  for (int i = 0; i < min(K,X); i++) {
    for (int j = 0; j < min(K,Y); j++) {
      D.push_back(A[i]+B[j]);
    }
  }
  sort(D.begin(),D.end(), greater<ll>());
  vector <ll> E;
  for (int i = 0; i < min((ll)(D.size()),K); i++) {
    E.push_back(D[i]);
  }
  vector<ll> ans;
  for (int i = 0; i < min((ll)(E.size()),K); i++) {
    for (int j = 0; j < Z; j++) {
      ans.push_back(E[i]+C[j]);
    }
  }
  sort(ans.begin(),ans.end(), greater<ll>());
  for (int i = 0; i < K; i++) {
    cout << ans[i] << endl;
  }
  return 0;
}