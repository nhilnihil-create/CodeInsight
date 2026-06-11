#include<bits/stdc++.h>
using namespace std;
int main(){
  long N,K;cin>>N>>K;
  vector<long>X(N),Y(N);for(long i=0;i<N;i++)cin>>X[i]>>Y[i];
  long ans=LONG_MAX;
  for(long a=0;a<N;a++)for(long b=a;b<N;b++)for(long c=b;c<N;c++)for(long d=c;d<N;d++){
    long y1=min(min(Y[a],Y[b]),min(Y[c],Y[d]));
    long y2=max(max(Y[a],Y[b]),max(Y[c],Y[d]));
    long x1=min(min(X[a],X[b]),min(X[c],X[d]));
    long x2=max(max(X[a],X[b]),max(X[c],X[d]));  
    long count=0;
    for(long i=0;i<N;i++)count+=(y1<=Y[i]&&Y[i]<=y2&&x1<=X[i]&&X[i]<=x2);
    if(count>=K)ans=min(ans,(y2-y1)*(x2-x1));
  }
  cout<<ans;
}


