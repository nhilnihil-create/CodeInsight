#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t N;
  cin>>N;
  int64_t l=pow(N,0.5);
  int64_t ans=0;
  for(int64_t i=1;i<=l;i++)
    if(N%i==0){
    if(2<=N/i-i)
      ans+=(N/i-1);
    }cout<<ans<<endl;
   return 0;
}