#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,m,n) for(int i=m;i<n;i++)
ll mod=1e9+7;

int main(){
  int n,z,w;
  cin>>n>>z>>w;
  int a[n];
  rep(i,0,n) cin>>a[i];
  if(n>1) cout<<max(abs(a[n-1]-w),abs(a[n-1]-a[n-2]));
  else cout<<abs(a[0]-w)<<endl;
}