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
  string S;
  ll K;
  cin>>S>>K;
  ll p = -1,c = 0;
  int l = S.size();
  rep(i,l) {
    if(S[i]!='1') {
      p = i;
      c = S[i] - '0';
      break;
    }
  }
  if(p+1>K||c==0) cout<<1<<endl;
  else cout<<c<<endl;
}