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
  cin>>N;
  vector<int> v(N);
  rep(i,N) cin>>v[i];
  bool can = true;
  vector<int> ans;
  while(!v.empty()){
    int l = v.size();
    bool done = false;
    rep(i,l){
      if(v[l-i-1]==l-i) {
        done = true;
        ans.push_back(l-i);
        v.erase(v.begin() + l - i-1);
        break;
      }
    }
    if(!done) {
      can = false;
      break;
    }
  }
  if(!can) cout<<-1<<endl;
  else {
    reverse(ans.begin(),ans.end());
    for(auto x:ans) cout<<x<<endl;
  }
}
