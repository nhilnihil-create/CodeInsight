#include <bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
  long long N,M;
  cin>>N>>M;
  int x[N]={};
  int y[N]={};
  int z[N]={};
  int f0[N];
  int f1[N];
  int f2[N];
  int f3[N];
  int f4[N];
  int f5[N];
  int f6[N];
  int f7[N];
  for(int i=0;i<N;i++){
    cin>>x[i]>>y[i]>>z[i];
    f0[i]=x[i]+y[i]+z[i];
    f1[i]=x[i]+y[i]-z[i];    
    f2[i]=x[i]-y[i]+z[i];
    f3[i]=-x[i]+y[i]+z[i];
    f4[i]=x[i]-y[i]-z[i];
    f5[i]=-x[i]+y[i]-z[i];    
    f6[i]=-x[i]-y[i]+z[i];
    f7[i]=-x[i]-y[i]-z[i];    
  }
  long long maxans=0;
  long long ans=0;
  sort(f0,f0+N);
  for(int i=N-1;i>=N-M;i--){
    ans+=f0[i];
  }
  maxans=max(maxans,ans);  
  
  ans=0;
  sort(f1,f1+N);
  for(int i=N-1;i>=N-M;i--){
    ans+=f1[i];
  }   
  maxans=max(maxans,ans);  
  
  ans=0;
  sort(f2,f2+N);
  for(int i=N-1;i>=N-M;i--){
    ans+=f2[i];
  }  
  maxans=max(maxans,ans);   

  ans=0;
  sort(f3,f3+N);
  for(int i=N-1;i>=N-M;i--){
    ans+=f3[i];
  }  
  maxans=max(maxans,ans); 
 
  ans=0;
  sort(f4,f4+N);
  for(int i=N-1;i>=N-M;i--){
    ans+=f4[i];
  }  
  maxans=max(maxans,ans); 

  ans=0;
  sort(f5,f5+N);
  for(int i=N-1;i>=N-M;i--){
    ans+=f5[i];
  }  
  maxans=max(maxans,ans); 
  
  ans=0;
  sort(f6,f6+N);
  for(int i=N-1;i>=N-M;i--){
    ans+=f6[i];
  }  
  maxans=max(maxans,ans);  
  
  ans=0;
  sort(f7,f7+N);
  for(int i=N-1;i>=N-M;i--){
    ans+=f7[i];
  }  
  maxans=max(maxans,ans); 
  
  cout<<maxans<<endl;
  
  return 0;
}

  
    