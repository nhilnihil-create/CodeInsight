#include <bits/stdc++.h>
#define r(i,n) for(int i=0;i<n;i++)
#define int long long
using namespace std;
typedef pair<int,int>P;
#define fi first
#define se second
int n,c,w[100009],v[100009],ans=0;
int A[100009],B[100009],C[100009],D[100009];
int W[1000009],w2[1000009];
main(){
  cin>>n>>c;
  r(i,n)cin>>w[i]>>v[i];

  r(p,2){
 
  r(i,n)W[i]=w[i];
 
  r(i,n)A[i]=v[i];
  r(i,n-1)A[i+1]+=A[i];
 
  r(i,n)B[i]=v[i];
  for(int i=n-1;i>0;i--)B[i-1]+=B[i];
  for(int i=n-1;i>=0;i--){
    if(i!=n-1)B[i]-=abs(c-w[i]);
    else B[i]-=abs(c-w[i]);
  }
  for(int i=n-1;i>0;i--){
    if(B[i-1]<=B[i]){
      B[i-1]=max(B[i-1],B[i]);
      W[i-1]=W[i];
    }
  }
  for(int i=0;i<n;i++){
    int sum=0;
    sum=A[i]-w[i];
    ans=max(ans,sum);
    if(i!=n-1)sum+=B[i+1];
    if(i!=n-1)sum-=min(abs(c-W[i+1]),w[i]);
    ans=max(ans,sum);
  }

  r(i,n/2)swap(w[i],w[n-i-1]);
  r(i,n/2)swap(v[i],v[n-i-1]);
  r(i,n)w[i]=abs(w[i]-c);

  }
 cout<<ans<<endl;
}