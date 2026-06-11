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
  cin>>N;
  vector<bitset<60>> vb(N);
  vector<ll> vl(N);
  for(ll i = 0LL; i < N; i++) {
    ll A;
    cin >> A;
    vl[i]=A;
    bitset<60> b(A);
    vb[i]=b;
  }
  ll ans = 0LL;
  ll j = 0LL;
  bitset<60> X;
  ll S = 0LL;
  for(ll i = 0LL; i < N; i++) {
    X=(X^vb[i]);
    S+=vl[i];
    ll x = X.to_ullong();
    while(x!=S){
      X=(X^vb[j]);
      S-=vl[j];
      x=X.to_ullong();
      j++;
    }
    ans+=i-j+1LL;
  }
  cout<<ans<<endl;
}