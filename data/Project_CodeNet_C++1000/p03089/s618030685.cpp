#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define all(x) (x).begin(),(x).end()
#define INF (1<<30)-1
using ll = long long;
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi b(n); rep(i,n){ cin >> b[i]; b[i]--; }
  vi ans(n);
  rep(i,n){
    int res = -1;
    rep(j,b.size()) if(j == b[j]) res = j;
    if(res == -1){
      cout << -1;
      return 0;
    }else{
      ans[i] = res;
      b.erase(b.begin()+res);
    }
  }
  reverse(all(ans));
  rep(i,n) cout << ans[i]+1 << endl;
  cout << "\n";
  return 0;
}
