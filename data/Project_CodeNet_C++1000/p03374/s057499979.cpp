#include "bits/stdc++.h"
using namespace std;
long long mod=1e9+7;
#define int long long

signed main(){
  int n,c;
  cin>>n>>c;
  vector<int> x(n);
  vector<int> v(n);
  for(int i=0;i<n;i++)cin>>x[i]>>v[i];
  if(n==1){
    int a=(v[0]+x[0]-c);
    int b=v[0]-x[0];
    int ans=0;
    ans=max(ans,max(b,a));
    cout<<ans<<endl;
    return 0;
  }
  vector<int> bestr(n);
  bestr[0]=max((int)0,v[0]-x[0]);
  int tmp=v[0]-x[0];
  for(int i=1;i<n;i++){
    tmp+=v[i];
    tmp-=abs(x[i]-x[i-1]);
    bestr[i]=max(bestr[i-1],tmp);
  }

  vector<int> bestl(n);
  bestl[n-1]=max((int)0,v[n-1]-abs(c-x[n-1]));
  tmp=v[n-1]-abs(c-x[n-1]);
  for(int i=n-2;i>=0;i--){
    tmp+=v[i];
    tmp-=abs(x[i]-x[i+1]);
    bestl[i]=max(bestl[i+1],tmp);
  }

  //for(int i=0;i<n;i++)cout<<bestr[i]<<" "<<bestl[i]<<endl;

  int ans=0;
  ans=max(ans,bestr[n-1]);
  ans=max(ans,bestl[0]);

  int np=v[0]-x[0];
  ans=max(ans,np+bestl[1]-x[0]);
  for(int i=1;i<n-1;i++){
    np+=v[i];
    np-=abs(x[i]-x[i-1]);
    ans=max(ans,np+bestl[i+1]-x[i]);
  }

  np=v[n-1]-abs(c-x[n-1]);
  ans=max(ans,np+bestr[n-2]-abs(c-x[n-1]));
  for(int i=n-2;i>0;i--){
    np+=v[i];
    np-=abs(x[i]-x[i+1]);
    ans=max(ans,np+bestr[i-1]-abs(c-x[i]));
  }
  cout<<ans<<endl;
}
