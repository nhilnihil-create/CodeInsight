#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
constexpr ll INF = 9e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod = 1000000007;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ---------------------------------------------------------------------------

int main(){
  int N,K;
  cin >> N >> K;
  vector<int> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  vector<ll> vec;
  for(int i=0; i<N; i++){
    ll sum = A[i];
    vec.push_back(sum);
    for(int j=i+1; j<N; j++){
      sum += A[j];
      vec.push_back(sum);
    }
  }
  ll ans = 0;
  vector<bool> use(vec.size(),true);
  for(int i=50; i>=0; i--){
    int cnt = 0;
    for(int j=0; j<vec.size(); j++){
      if(!use[j]) continue;
      if(vec[j] & (1LL<<i)) cnt++;
    }
    if(cnt >= K){
      for(int j=0; j<vec.size(); j++){
        if(!(vec[j] & (1LL<<i))) use[j] = false;
      }
      ans += (1LL<<i);
    }
  }
  cout << ans << endl;
  return 0;
}
