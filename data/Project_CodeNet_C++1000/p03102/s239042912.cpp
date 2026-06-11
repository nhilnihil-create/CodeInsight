#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  int n, m, c;
  cin >> n >> m >> c;
  vi b(m);
  vvi a(n,vector<int>(m));
  rep(i,m) cin >> b[i];
  rep(i,n)rep(j,m) cin >> a[i][j];
  int ans=0;
  rep(i,n){
    ll sum=c;
    rep(j,m){
      sum += a[i][j]*b[j];
    }
    if(sum>0) ans++;
  }
  cout << ans << endl; 
}
