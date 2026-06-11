#include<bits/stdc++.h>
using namespace std;
int64_t f(int64_t x){
  int64_t ans=0;
  if(x%4==1 || x%4==2)
    ans+=1;
for(int64_t i=2;i<=41;i++){
  int64_t k=pow(2,i);
  int64_t mod=x%k;
  if(k/2<=mod){
  if(mod%2==0)
    ans+=(k/2);
  }
} return ans;
}
int main(){
int64_t A,B;
  cin>>A>>B;
  int64_t a=f(A-1);
  int64_t b=f(B);
  int64_t ans=a^b;
  cout<<ans<<endl;
    return 0;
}
