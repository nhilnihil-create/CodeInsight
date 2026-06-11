#include <bits/stdc++.h>
#define rep(i,a,n) for(int i =a; i<n; i++)
#define ll long long
using namespace std;

int main() {
  int N,M,Q; cin >> N >> M >> Q;
  int L[M],R[M]; rep(i,0,M) cin >> L[i] >> R[i];
  
  vector<vector<int>> d(N+1,vector<int>(N+1,0));
  rep(i,0,M) d[L[i]][R[i]]++;
  
  vector<vector<ll>> sum(N+1,vector<ll>(N+1,0));
  rep(i,1,N+1) {
    sum[i][1] = d[i][1];
    rep(j,2,N+1) {
      sum[i][j] = sum[i][j-1] + d[i][j];
    }
  }
    
  rep(i,0,Q) {
    int a,b,ans =0; cin >> a >> b;
    rep(j,a,b+1) ans += sum[j][b];
    cout << ans << endl;
  }
}  