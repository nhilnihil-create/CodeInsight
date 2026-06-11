#include <bits/stdc++.h>
#define int long long
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define F first
#define S second

using namespace std;
typedef pair<int,int> P;

const int MOD=1000000007;
int INF=100100100100100;

signed main(){
  int ans=0;
  int n,z,w;cin>>n>>z>>w;
  int a[2010];
  rep(i,n)cin>>a[i];
  if(n==1)ans=abs(a[n-1]-w);
  else ans=max(abs(a[n-1]-w),abs(a[n-2]-a[n-1]));
  cout<<ans<<endl;
  return 0;
}