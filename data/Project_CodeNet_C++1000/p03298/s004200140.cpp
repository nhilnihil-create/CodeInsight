#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<string,string>;
using graph = vector<vector<ll>>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int N;
  string S;
  cin>>N>>S;
  string L,R;
  rep(i,N) L += S[i];
  rep(i,N) R += S[N*2-i-1];
  map<P,ll> m,n;
  rep(i,(1LL<<N)){
    string a,b,c,d;
    rep(j,N){
      if(i&(1LL<<j)) {
        a += L[j];
        c += R[j];
      }
      else {
        b += L[j];
        d += R[j];
      }
    }
    m[make_pair(a,b)]++;
    n[make_pair(c,d)]++;
  }
  ll ans = 0;
  for(auto x:m){
    ans += x.second*n[x.first];
  }
  cout<<ans<<endl;
}