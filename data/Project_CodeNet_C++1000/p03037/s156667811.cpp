#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll MOD=1000000007;

int main(){
  int n,m; cin>>n>>m;
  vector<int>L(m);
  vector<int>R(m);
  rep(i,m) cin>>L[i]>>R[i];
  int max_L = L[0];
  int min_R = R[0];
  for (int i=1; i<m; i++){
    if (max_L < L[i]) max_L = L[i];
    if (min_R > R[i]) min_R = R[i];
  }
  int ans = min_R - max_L + 1;
  if (ans>0) cout << ans << endl;
  else cout << 0 << endl;
}