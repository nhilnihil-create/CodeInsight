#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  ll N, K;
  cin>>N>>K;
  ll ans;
  if(K%2LL==1LL){
    ll t = N/K;
    ans = t*t*t;
  }
  if(K%2LL==0LL){
    ll t = N/K;
    ll s = (N+(K/2LL))/K;
    ans = t*t*t+s*s*s;
  }
  cout<<ans<<endl;
}