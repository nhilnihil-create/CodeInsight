#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod ll(1e9+7)
ll exp(ll a,ll b)
{
  if(b==0)
    return 1;
  if(b%2==0)
    return exp(a*a%mod,b/2);
  return a*exp(a*a%mod,(b-1)/2)%mod;
}
int main()
{
  #ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
  #endif
   int n,m;
   cin>>n>>m;
   vector<int>adj[m+1];
   for(int i=1; i<=m; i++){
    int size;
    cin>>size;
    while(size--){
      int num;
      cin>>num;
      adj[i].push_back(num);
    }
   }
   vector<int>p(m+1);
   for(int i=1; i<=m; i++)
    cin>>p[i];
   int ans=0;
   for(int i=0; i<(1<<n); i++){
    int cnt=0;
    for(int j=1; j<=m; j++){
      int temp=0;
      for(int k=0; k<adj[j].size(); k++){
        int var=adj[j][k];
        var--;
        if(i&(1<<var)){
          temp++;
        }
      }
      if(temp%2==p[j])
        cnt++;
    }
    if(cnt==m)
      ans++;
   }
   cout<<ans;

   return 0;
}