#include<bits/stdc++.h>
using namespace std;
#define INFTY 1<<20
typedef long long int ll;
const int MOD=1000000007;


  
int main(){
  int n;cin>>n;
  vector<int>a(n+2);
  a[0]=0,a[n+1]=0;
  ll sum=0,dis[n];
  for (int i = 1; i <= n; i++)
  {
    cin>>a[i];
    sum += abs(a[i]-a[i-1]);
  }
  sum += abs(a[n+1]-a[n]);
  for (int i = 1; i <=n; i++)
  {
    ll ans=0;
    ans = sum-abs(a[i]-a[i-1])-abs(a[i+1]-a[i])+abs(a[i+1]-a[i-1]);
    cout<<ans<<endl;
  }
  
    return 0;
}