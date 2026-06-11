#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int main(){
  int n,z,w;
  cin>>n>>z>>w;
  vector<int>a(n);
  rep(i,n)cin>>a[i];
  if(n==1)cout<<abs(a[0]-w)<<endl;
  else cout<<max(abs(a[n-1]-w),abs(a[n-2]-a[n-1]))<<endl;
}