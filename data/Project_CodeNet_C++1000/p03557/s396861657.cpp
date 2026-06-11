#include<bits/stdc++.h>
using namespace std;
long bs1(long x,const vector<long>& v){
  long l=-1,r=v.size();
  while(r-l>1){
    long z=(l+r)/2;
    if(v[z]>=x)r=z;
    else l=z;
  }
  return l;
}
long bs2(long x,const vector<long>& v){
  long l=-1,r=v.size();
  while(r-l>1){
    long z=(l+r)/2;
    if(v[z]>x)r=z;
    else l=z;
  }
  return l;
}
int main(){
  long N;cin>>N;
  vector<long>A(N),B(N),C(N);
  for(long i=0;i<N;i++)cin>>A[i];
  for(long i=0;i<N;i++)cin>>B[i];
  for(long i=0;i<N;i++)cin>>C[i];
  sort(A.begin(),A.end());
  sort(C.begin(),C.end());
  long s=0;
  for(long i=0;i<N;i++){
    s+=(1+bs1(B[i],A))*(N-1-bs2(B[i],C));
  }cout<<s<<endl;
  
}

/*



*/