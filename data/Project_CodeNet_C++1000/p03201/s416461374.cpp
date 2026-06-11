#include<bits/stdc++.h>
#define endl '\n';
using namespace std;
using ll = long long;
using P = pair<int,int>;
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("Ofast")
constexpr ll INF = 1e18;
constexpr int inf = 1e9;
constexpr double INFD = 1e100;
constexpr ll mod2 = 1000000007;
constexpr ll mod = 998244353;
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
  vector<ll> A(N);
  for(int i=0; i<N; i++){
    cin >> A[i];
  }
  sort(A.begin(),A.end(),greater<ll>());
  unordered_map<ll,ll> mp;
  for(int i=0; i<N; i++){
    mp[A[i]]++;
  }
  int ans = 0;
  for(int i=0; i<N; i++){
    if(mp[A[i]] == 0) continue;
    mp[A[i]]--;
    for(int j=40; j>=0; j--){
      if(!mp.count((1LL<<j)-A[i])) continue;
      if(mp[(1LL<<j) - A[i]] > 0){
        ans++;
        mp[(1LL<<j)-A[i]]--;
      }      
    }
  }
  cout << ans << endl;
  return 0;
}
