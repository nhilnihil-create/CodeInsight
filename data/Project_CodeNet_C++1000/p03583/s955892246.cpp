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
  ll N;
  cin>>N;
  ll a,b,c;
  rep(i,3501){
    rep(j,3501){
      if(i==0||j==0) continue;
      ll p = N*i*j;
      ll q = 4LL*i*j-N*(i+j);
      if(q<=0) continue;
      if(p%q==0) {
        a=i;
        b=j;
        c=p/q;
        break;
      }
    }
  }
  cout<<a<<" "<<b<<" "<<c<<endl;
}