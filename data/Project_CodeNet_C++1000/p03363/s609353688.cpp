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
  vector<ll> S(N);
  map<ll,ll> m;
  for(ll i = 0LL ; i< N; i++) {
    ll A;
    cin>>A;
    if(i==0LL) S[i]=A;
    else S[i]=S[i-1LL]+A;
    m[S[i]]++;
  }
  ll ans = 0LL;
  m[0]++;
  for(auto x:m){
    ans+=x.second*(x.second-1LL)/2LL;
  }
  cout<<ans<<endl;
}