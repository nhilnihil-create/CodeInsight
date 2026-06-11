#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t N,K;
  cin>>N>>K;
  int64_t ans=0;
  if(K==0)
    cout<<N*N<<endl;
  else{
  for(int64_t b=K+1;b<=N;b++){
  int64_t a=N/b;
    int64_t k=N%b;
    int64_t zero=0;
    int64_t x=a*(b-K)+max(k-K+1,zero);
    ans+=x;
  
  }cout<<ans<<endl;
  }
   return 0;
}
