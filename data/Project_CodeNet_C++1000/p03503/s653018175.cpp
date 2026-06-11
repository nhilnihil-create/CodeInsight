#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define rep2(i,a,n) for(int i=(a); i<(n); i++)
#define all(vec) vec.begin(),vec.end()
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vll = vector<ll>;
int main() {
  int N; cin >> N;
  vvi time(N, vi(10));
  vvi prf(N, vi(11)); 
  rep(i,N){
    rep(j,10){ int a; cin >> a; time[i][j]=a;}
  }
  rep(i,N){
    rep(j,11){ int a; cin >> a; prf[i][j]=a;}
  }

  int ans =-1e10;
  for (int bit=1; bit<(1<<10); bit++){
    int pr = 0;
    vi opn(N,0);
    for (int i=0; i<10; i++){
      if(bit & (1<<i)) {
        rep(j,N){
            if(time[j][i] == 1) opn[j]++;
        } 
      }
    }
    rep(i,N) pr += prf[i][opn[i]];
    if (ans < pr) ans = pr;
  }
  cout << ans << endl;
}