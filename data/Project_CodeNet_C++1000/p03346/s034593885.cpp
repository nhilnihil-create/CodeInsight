#include<bits/stdc++.h>
#define endl '\n';
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod = 1000000007;
constexpr ll mod2 = 998244353;
const double PI = 3.1415926535897932384626433832795028841971;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
// ios::sync_with_stdio(false);
// cin.tie(nullptr);
// ---------------------------------------------------------------------------

int main(){
  int N;
  cin >> N;
  vector<int> A(N);
  vector<int> pos(N);
  rep(i,N){
    cin >> A[i];
    A[i]--;
    pos[A[i]] = i;
  }
  // for(int i=0; i<N; i++){
  //   cout << i << " " << pos[i] << endl;
  // }
  int mx = 0;
  int cnt = 1;
  rep(i,N-1){
    if(pos[i] < pos[i+1]){
      cnt++;
    }else{
      chmax(mx,cnt);
      cnt = 1;
    }
  }
  chmax(mx,cnt);
  cout << N-mx << endl;
  return 0;
}