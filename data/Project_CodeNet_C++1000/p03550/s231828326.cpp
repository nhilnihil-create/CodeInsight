#define _GLIBCXX_DEBUG

#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

constexpr ll INF = 1e16;

#define rep(i, N) for(ll i=0; i<N; ++i)

ll max(ll a, ll b) {return a < b ? b : a; }
ll min(ll a, ll b) {return a > b ? b : a; }

int main() {
  int N;
  ll Z, W;
  cin >> N >> Z >> W;
  vector<ll> a(N);
  for(int i=0; i<N; ++i) {
    cin >> a[i];
  }
  
  if(N == 1) {
    cout << abs(W-a.back()) << endl;
  } else {
    cout << max(abs(W - a.back()), abs(a.back() - a[a.size()-2])) << endl;
  }
}