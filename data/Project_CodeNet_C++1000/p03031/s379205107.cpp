#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n,m; cin >> n >> m;
  vi k(m),p(m);
  vector<vi> s(m);
  rep(i,m){
    cin >> k[i];
    s[i].resize(k[i]);
    rep(j,k[i]) cin >> s[i][j];
  }
  rep(i,m) cin >> p[i];

  int ans = 0;
  rep(bit,1<<n){
    vi check(m);
    rep(i,n){
      if(bit >> i & 1){
        rep(j,m){
          rep(a,k[j]) if(s[j][a] == i+1) check[j] ^= 1;
        }
      }
    }
    bool ok = true;
    rep(i,m) if(p[i] != check[i]) ok = false;
    if(ok) ans++;
  }
  cout << ans;
  cout << "\n";
  return 0;
}
