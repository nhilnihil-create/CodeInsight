#include<bits/stdc++.h>
using namespace std;
#define int long long
#define double long double
#define SZ(x) ((int)(x).size())
#define rep(i,n) for(int i=0;i<(n);++i)
#define fore(i,a) for(auto &i:a)
#define min(...) min({__VA_ARGS__})
#define max(...) max({__VA_ARGS__})
#define Yes cout << "Yes" << endl;
#define No cout << "No" << endl;
#define answer cout << ans << endl;
signed _main(); signed main() { cin.tie(0); ios::sync_with_stdio(false); _main(); }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> using v = vector<T>;
template<class T> using vv = vector<v<T>>;
const int MOD=1e9+7;
const long long INF = 1LL << 60;

signed _main(){
  int N; cin >> N;
  v<int> a(N),b(N);
  rep(i,N) cin >> a[i];
  rep(i,N) cin >> b[i];
  int res=0,dif=0;
  rep(i,N){
    if(b[i]-a[i]>=2){
      res+=(b[i]-a[i])/2;
    }
    if(a[i]>b[i]) dif+=a[i]-b[i];
  }
  if(res>=dif) Yes
  else No
  return 0;
}
