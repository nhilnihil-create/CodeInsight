#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const double PI = acos(-1);
const ll MOD = 1000000007;
using Graph = vector<vector<int>>;


int main() {
  ll N,K; cin >> N >> K;

  ll count = 0;
  for (ll i = K+1; i <= N; i++) {
    ll n = N / i;
    count += (i - K) * n;
    count += max(ll(0),N - n * i - K + 1);
    if (K == 0) count--;
  }


  cout << count << endl;
}