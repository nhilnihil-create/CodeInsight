#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<cstring>
#include<math.h>
#include<bitset>
#include<queue>
#include<set>
#include<iomanip>
#include<assert.h>
#include<string>
#include<cstdlib>
#include<cctype>
#include<unordered_map>
#include<sstream>
#include<numeric>
#include<stack>
// #include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
const double INFD = 1e100;
const ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmin(T& a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
};
template<class T> inline bool chmax(T& a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
};

// intやllをstringに変換
template<typename T> inline string toString(const T &a){
  ostringstream oss;
  oss << a;
  return oss.str();
};
// ----------------------------------------------------------------------------


int main(){
  int N,K;
  cin >> N >> K;
  vector<pair<ll,ll>> p(N);
  for(int i=0; i<N; i++){
    ll x,y;
    cin >> x >> y;
    p[i] = make_pair(x,y);
  }
  vector<ll> x(N),y(N);
  for(int i=0; i<N; i++){
    tie(x[i],y[i]) = p[i];
  }
  sort(x.begin(),x.end());
  sort(y.begin(),y.end());
  ll ans = INF;
  for(int i=0; i<N; i++){
    for(int j=i+1; j<N; j++){
      for(int k=0; k<N; k++){
        for(int l=k+1; l<N; l++){
          int cnt = 0;
          for(int m=0; m<N; m++) if(x[i]<=p[m].first && p[m].first<=x[j] && y[k]<=p[m].second && p[m].second<=y[l]) cnt++;
          if(cnt < K) continue;
          chmin(ans,(x[j]-x[i])*(y[l]-y[k]));
        }
      }
    }
  }
  cout << ans << endl;
  return 0;
}
