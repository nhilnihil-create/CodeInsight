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
  int N, M; cin >> N >> M;
  vvi sw(M, vi(0)); 
  rep(i,M){
    int k; cin >> k;
    rep(j,k){
      int a; cin >> a;
      sw[i].push_back(a);
    }
  }
  vi lt(M);
  rep(i,M){ int a; cin >> a; lt[i]=a;}
    
  int ans =0;
  for (int bit=0; bit<(1<<N); bit++){
    vi jg(M,0);
    for (int i=0; i<N; i++){
      if(bit & (1<<i)) {
        rep(k,M){
          rep(l, (int)sw[k].size()){
            if(i == (sw[k][l]-1) ) jg[k]++;
          }
        } 
      }
    }
    rep(i,M) jg[i] %=2;
    if(lt==jg) ans++;
  }
  cout << ans << endl;
}