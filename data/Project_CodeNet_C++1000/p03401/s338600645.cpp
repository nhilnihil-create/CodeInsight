#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
const long long MOD=1e9+7;

int main() {
  int n;
  cin>>n;
  vector<int> A(n+2);
  A[0]=0;
  rep(i,n) cin>>A[i+1];
  A[n+1]=0;
  vector<int> lsums(n+2);
  lsums[0]=0;
  rep(i,n+1) lsums[i+1]=lsums[i]+abs(A[i+1]-A[i]);
  reverse(A.begin(),A.end());
  vector<int> rsums(n+2);
  rsums[0]=0;
  rep(i,n+1) rsums[i+1]=rsums[i]+abs(A[i+1]-A[i]);
  reverse(A.begin(),A.end());
  
  rep(i,n){
    int ans=0;
    ans+=lsums[i];
    ans+=rsums[n-i-1];
    ans+=abs(A[i]-A[i+2]);
    cout<<ans<<endl;
  }
  return 0;
}
