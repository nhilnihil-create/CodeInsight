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
  vector<int> cnt(13,0);
  for(int i=0; i<N; i++){
    int a;
    cin >> a;
    cnt[a]++;
  }
  if(cnt[0]){
    cout << 0 << endl;
    return 0;
  }
  if(cnt[12] >= 2){
    cout << 0 << endl;
    return 0;
  }
  for(int i=1; i<=12; i++){
    if(cnt[i] >= 3){
      cout << 0 << endl;
      return 0;
    }
  }
  int ans = 0;
  for(int bit=0; bit<(1<<12); bit++){
    set<int> se;
    se.insert(0);
    se.insert(24);
    if(cnt[12]){
      se.insert(12);
    }
    for(int i=1; i<12; i++){
      if(cnt[i] == 2){
        se.insert(i);
        se.insert(24-i);
      }else if(cnt[i] == 1){
        if(bit & (1<<(i-1))){
          se.insert(i);
        }else{
          se.insert(24-i);
        }
      }
    }
    int pos = *se.begin();
    se.erase(pos);
    int res = 30;
    while(se.size()){
      chmin(res,*se.begin()-pos);
      pos = *se.begin();
      se.erase(pos);
    }
    chmax(ans,res);
  }
  cout << ans << endl;
  return 0;
}