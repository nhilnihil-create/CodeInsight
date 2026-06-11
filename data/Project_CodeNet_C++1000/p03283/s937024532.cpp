#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
  int n,m,Q;
  cin >> n >> m >> Q;
  vector<int>l(m),r(m);
  for(int i=0; i<m; i++){
    cin >> l[i] >> r[i];
  }
  vector<int>p(Q),q(Q);
  for(int i=0; i<Q; i++){
    cin >> p[i] >> q[i];
  }
  
  vector<vector<int>>sum(n+1,vector<int>(n+1,0));
  for(int i=0; i<m; i++) sum[l[i]][r[i]]++;
  
  for(int i=1; i<=n; i++){
   for(int j=1; j<=n; j++){
     sum[i][j] += sum[i-1][j];
     sum[i][j] += sum[i][j-1];
     sum[i][j] -= sum[i-1][j-1];
   }
  }
  
  for(int i=0; i<Q; i++){ 
    int ans = sum[q[i]][q[i]]-sum[q[i]][p[i]-1]-sum[p[i]-1][q[i]]+sum[p[i]-1][p[i]-1];
    cout << ans << endl;
  }
  
  
}