#include<bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using pii = pair<int,int>;
ll MOD=1000000007;

int main(){
  int n,x; cin>>n>>x;
  vector<int>A(n);
  rep(i,n) cin>>A[i];
  sort(A.begin(), A.end());
  int ans = 0;
  rep(i,n){
    if (x>=A[i]){
      ans++;
      x -= A[i];
    }
  }
  if (x == 0||ans<n) cout << ans;
  else cout << ans-1;
}