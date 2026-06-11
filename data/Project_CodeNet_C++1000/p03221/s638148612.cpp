#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

#define zero_pad(num) setfill('0') << right << setw(num)

int main(){
  int N, M;
  cin >> N >> M;

  vector<ll> P(M);
  vector<ll> Y(M);
  vector<vector<ll>> X(N);

  rep(i, M){
    cin >> P[i] >> Y[i];
    P[i]--;
    X[P[i]].push_back(Y[i]);
  }

  rep(i, N){
    sort(X[i].begin(), X[i].end());
  }

  rep(i, M){
    ll upper = P[i] + 1;
    ll lower = lower_bound(X[P[i]].begin(), X[P[i]].end(), Y[i]) - X[P[i]].begin() + 1;
    cout << zero_pad(6) << upper << zero_pad(6) << lower << endl;
  }
}