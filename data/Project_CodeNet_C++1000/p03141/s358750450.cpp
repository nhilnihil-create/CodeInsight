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
  int N;
  cin >> N;
  vector<int> A(N),B(N);
  ll ans = 0;
  for(int i=0; i<N; i++){
    cin >> A[i] >> B[i];
    ans -= B[i];
  }
  vector<ll> sum(N);
  for(int i=0; i<N; i++){
    sum[i] = A[i] + B[i];
  }
  sort(sum.begin(),sum.end(),greater<ll>());
  for(int i=0; i<N; i+=2){
    ans += sum[i];
  }
  cout << ans << endl;
  return 0;
}
