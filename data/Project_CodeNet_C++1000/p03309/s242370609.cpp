#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N;
  cin >> N;
  vector<ll> v(N);
  for(ll i = 0LL; i < N; i++) {
    ll x;
    cin>>x;
    v[i]=x-i-1LL;
  }
  sort(v.begin(),v.end());
  ll ans = 0LL;
  for(ll i = 0LL; i < N; i++) {
    ans += abs(v[i]-v[N/2LL]);
  }
  cout<<ans<<endl;
}  