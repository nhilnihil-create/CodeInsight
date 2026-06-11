#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int N;
  cin>>N;
  std::vector<int> a(N),b(N);
  for(int i=0;i<N;i++)cin>>a[i];
  for(int i=0;i<N;i++)cin>>b[i];
  int ans=0;
  std::vector<int> va(N),vb(N);
  int pp=2;
  for(int k=0;k<30;k++){
    for(int i=0;i<N;i++){
      va[i]=a[i]%pp;
      vb[i]=b[i]%pp;
    }
    int f=0;
    sort(vb.begin(),vb.end());
    for(int i=0;i<N;i++){
      int m=-1;
      int A=pp/2-va[i];
      if(vb[0]>=A)m=0;
      if(vb[N-1]<A)m=N;
      if(m==-1){
        int l=1;
        int r=N-1;
        m=(l+r)/2;
        while(vb[m]<A||vb[m-1]>=A){
          if(vb[m]<A)l=m+1;
          else r=m;
          m=(l+r)/2;
        }
      }
      int m1=m;//cout<<m1<<" ";
      m=-1;
      A=pp-va[i];
      if(vb[0]>=A)m=0;
      if(vb[N-1]<A)m=N;
      if(m==-1){
        int l=1;
        int r=N-1;
        m=(l+r)/2;
        while(vb[m]<A||vb[m-1]>=A){
          if(vb[m]<A)l=m+1;
          else r=m;
          m=(l+r)/2;
        }
      }
      int m2=m;//cout<<m2<<" ";
      f+=m2-m1;
      m=-1;
      A=pp/2+pp-va[i];
      if(vb[0]>=A)m=0;
      if(vb[N-1]<A)m=N;
      if(m==-1){
        int l=1;
        int r=N-1;
        m=(l+r)/2;
        while(vb[m]<A||vb[m-1]>=A){
          if(vb[m]<A)l=m+1;
          else r=m;
          m=(l+r)/2;
        }
      }
      m1=m;//cout<<m1<<" ";
      m=-1;
      A=pp-va[i]+pp;
      if(vb[0]>=A)m=0;
      if(vb[N-1]<A)m=N;
      if(m==-1){
        int l=1;
        int r=N-1;
        m=(l+r)/2;
        while(vb[m]<A||vb[m-1]>=A){
          if(vb[m]<A)l=m+1;
          else r=m;
          m=(l+r)/2;
        }
      }
      m2=m;//cout<<m2<<endl;
      f+=m2-m1;
    }
    ans+=(f%2)*pp/2;
    pp*=2;
    //cout<<f<<" "<<ans<<endl;
  }
  cout<<ans<<endl;
}
