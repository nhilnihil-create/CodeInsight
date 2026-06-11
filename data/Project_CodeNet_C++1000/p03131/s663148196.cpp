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
  int K,A,B;
  cin >> K >> A >> B;
  if(K <= A || B<=A+2){
    cout << K+1 << endl;
    return 0;
  }
  K -= A-1;
  ll ans = A;
  ans += (K/2LL)*(B-A);
  if(K%2){
    ans++;
  }
  cout << ans << endl;
  return 0;
}
