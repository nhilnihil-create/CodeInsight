#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;

typedef pair<ll, ll> p_ll;

int main() {
  ll N; cin >> N;
  ll A[N], B[N]; rep(i,N) cin >> A[i] >> B[i];
  p_ll dish[N]; rep(i,N) dish[i] = make_pair(A[i],B[i]);
  sort(dish,dish+N,[](const p_ll &x, const p_ll &y){return x.first+x.second>y.first+y.second;});

  ll result = 0; rep(i,N) result += A[i];
  rep(i,N/2) result -= dish[i*2+1].first + dish[i*2+1].second;
  cout << result << endl;
  return 0;
}