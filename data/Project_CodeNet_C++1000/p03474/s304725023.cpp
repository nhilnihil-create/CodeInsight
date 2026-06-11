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
  int A,B;
  cin>>A>>B;
  string S;
  cin>>S;
  bool ok = true;
  rep(i,A+B+1){
    if(i<A||i>A){
      int t = S[i] - '0';
      if(t<0||t>=10) ok = false;
    }
    else {
      if(S[i]!='-') ok = false;
    }
  }
  if(ok) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}