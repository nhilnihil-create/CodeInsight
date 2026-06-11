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
  ll N;
  cin>>N;
  vector<ll> v(5,0);
  rep(i,N){
    string S;
    cin>>S;
    if(S[0]=='M') v[0]++;
    if(S[0]=='A') v[1]++;
    if(S[0]=='R') v[2]++;
    if(S[0]=='C') v[3]++;
    if(S[0]=='H') v[4]++;
  }
  ll ans = 0;
  rep(i,3){
    for(int j = i+1;j < 4; j++){
      for(int k = j+1; k<5; k++){
        ans += v[i]*v[j]*v[k];
      }
    }
  }
  cout<<ans<<endl;
}