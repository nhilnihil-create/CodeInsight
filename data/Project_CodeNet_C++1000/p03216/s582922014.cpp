#include <bits/stdc++.h>
using namespace std;

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

using ll = long long;
using lb = long double;
using P = pair<ll,ll>;
using graph = vector<vector<ll>>;
using V = vector<ll>;

const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
const ll INF = 1LL<<60;
const ll mod = 1000000007LL;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll hcnt[300005],wcnt[300005];

int main() {
  ll N,Q;
  string S;
  cin>>N>>S>>Q;
  vector<ll> cntD(N+1,0),cntM(N+1,0);
  rep(i,N){
    if(S[i]=='D') cntD[i+1]++;
    if(S[i]=='M') cntM[i+1]++;
  }
  rep(i,N) {
    cntD[i+1]+=cntD[i];
    cntM[i+1]+=cntM[i];
  }
  vector<ll> cntDM(N+1,0);
  rep(i,N){
    if(S[i]=='M') cntDM[i+1] += cntD[i+1];
  }
  rep(i,N) cntDM[i+1]+=cntDM[i];
  rep(i,Q){
    ll k;
    cin>>k;
    ll ans = 0;
    rep(i,N){
      if(S[i]=='C') {
        ll DM = cntDM[i]-cntDM[max(0LL,i-k+1)];
        DM -= cntD[max(0LL,i-k+1)]*(cntM[i]-cntM[max(0LL,i-k+1)]);
        ans += DM;
      }
    }
    cout<<ans<<endl;
  }
}