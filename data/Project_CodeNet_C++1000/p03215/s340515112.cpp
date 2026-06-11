#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

#define rep(i, N) for (int i = 0; i < (int)N; i++)
const ll MOD = pow(10,9)+7;
const ll LLINF = pow(2,61)-1;
const int INF = pow(2,30)-1;


int main() {
  int N, K; cin >> N >> K;
  ll a[N+1]={}; 
  rep(i,N) { cin >> a[i+1]; a[i+1] += a[i]; }
  vector<ll> sum; rep(i,N+1) for (int j=i+1; j<=N; j++) sum.push_back(a[j]-a[i]);

  ll result = 0;
  for(int i=40; i>=0; i--) {
    ll now = (1ull<<i);
    int count = 0;
    for (auto x: sum) {
      if ((x&(result+now))==result+now) count++;
    }
    if (count>=K) result += now;
  }
  cout << result << endl;
  return 0;
}