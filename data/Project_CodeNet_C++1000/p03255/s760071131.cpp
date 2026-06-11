#include<iostream>
#define int long long
using namespace std;
const int N=2e5+2;
const int inf=3e18+2;
int ar[N],sum[N];
signed main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  int n,i,j,k,l,x,ans,cur,now;
  cin>>n>>x;
  ans=inf;
  //cout<<ans<<endl;
  for(i=1;i<=n;i++){
    cin>>ar[i];
    sum[i]=sum[i-1]+ar[i];
  }
  bool cac=true;
  for(i=1;i<=(n+1)/2;i++){
    j=n;
    cur=x*n+i*x;
    cac=true;
    now=7;
    while(j){
      if(cac){
        k=max(j-2*i,0ll);
        if(cur+5*(sum[j]-sum[k])<=inf){
          cur+=5*(sum[j]-sum[k]);
          j=k;
          cac=false;
        }
        else{
          cac=true;
          break;
        }
      }
      else{
        k=max(j-i,0ll);
        if(cur+now*(sum[j]-sum[k])<=inf){
          cur+=now*(sum[j]-sum[k]);
          j=k;
          cac=false;
          now+=2;
        }
        else{
          cac=true;
          break;
        }
      }
    }
    //cout<<i<<' '<<cur<<' ';
    if(!cac){
      ans=min(ans,cur);
    }
  }
  cout<<ans;
}