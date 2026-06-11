#include<bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define ll long long
#define rep(i,n) for(int i = 0; i < int(n); i++)
#define vi vector<int>
#define INF (1<<30)-1
using namespace std;
const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
template<class T> inline bool chmax(T &a, const T &b){ if(a<b) { a=b; return 1; } return 0; }
template<class T> inline bool chmin(T &a, const T &b){ if(b<a) { a=b; return 1; } return 0; }

int main(){
  cin.tie(0), ios::sync_with_stdio(false);
  int n; cin >> n;
  vi c(n-1),s(n-1),f(n-1);
  rep(i,n-1) cin >> c[i] >> s[i] >> f[i];

  vi ans(n);
  rep(i,n-1){
    rep(j,i+1){
      if(s[i] < ans[j]){
        int t = ans[j];
        while (t%f[i] != 0) t++;
        ans[j] = c[i]+t;
      }else{
        ans[j] = c[i]+s[i];
      }
    }
  }
  rep(i,n) cout << ans[i] << endl;
  cout << "\n";
  return 0;
}
