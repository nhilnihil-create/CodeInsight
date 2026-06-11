#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  vector<bool> sim(100005,false);
  vector<bool> prime(100005,true);
  for(ll i = 2; i < 100005; i++){
    if(prime[i]) {
      for(ll j = 2; i*j<100005; j++) prime[i*j] = false;
    }
  }
  prime[0] = prime[1] = false;
  rep(i,100005){
    if(i%2==1&&prime[i]&&prime[(i+1)/2]) sim[i] = true;
  }
  vector<ll> S(100005,0);
  rep(i,100005){
    if(i==0) continue;
    if(sim[i]) S[i] = S[i-1] + 1;
    else S[i] = S[i-1]; 
  }
  ll Q;
  cin>>Q;
  rep(i,Q){
    ll l,r;
    cin>>l>>r;
    cout<<S[r]-S[l-1]<<endl;
  }
}