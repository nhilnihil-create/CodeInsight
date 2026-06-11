#include<bits/stdc++.h>
using namespace std;
int main(){
  long N,K;cin>>N>>K;
  vector<long>A(N);for(long i=0;i<N;i++)cin>>A[i];
  
  long x=0,ans=0;
  for(long b=LONG_MAX-LONG_MAX/2;b>0;b/=2){
    long c=0;
    for(long j=0;j<N;j++)c+=((A[j]&b)!=0);
    if(x+b<=K&&c<N-c){x+=b;ans+=b*(N-c);}
    else ans+=b*c;
  }
  cout<<ans;
}

