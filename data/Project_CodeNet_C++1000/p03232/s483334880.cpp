#include<bits/stdc++.h>
using namespace std;
static const int64_t mod=1000000007;
int64_t f(int64_t x,int64_t y){
if(y==0)
  return 1;
  else if(y%2==0)
    return (f(x,y/2)*f(x,y/2))%mod;
  else
    return (x*((f(x,y/2)*f(x,y/2))%mod))%mod;
}
int main(){
  int64_t N; cin>>N;
  vector<int64_t>A(N);
  for(int64_t i=0;i<N;i++)
    cin>>A.at(i);
  int64_t n=1;
  for(int64_t i=1;i<=N;i++)
    n=(n*i)%mod;
  vector<int64_t>B(N+1);
  B[0]=0;
  for(int64_t i=1;i<=N;i++)
    B[i]=(B[i-1]+(n*f(i,mod-2))%mod)%mod;
  int64_t ans=0;
  for(int64_t i=0;i<N;i++){
  int64_t b=(B[N-i]+B[i+1]-B[1]+mod)%mod;
    ans=(ans+A[i]*b)%mod;
  }cout<<ans<<endl;
  return 0;
}