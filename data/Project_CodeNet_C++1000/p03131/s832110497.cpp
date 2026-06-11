#include<bits/stdc++.h>
using namespace std;
int main(){
int64_t K,A,B;
  cin>>K>>A>>B;
  if(B-A<=1 || K<=A)
    cout<<K+1<<endl;
  else{
  if((K-A+1)%2==0){
  int64_t ans=A+(B-A)*(K-A+1)/2;
    cout<<ans<<endl;
  
  }else{
  int64_t ans=1+A+(B-A)*((K-A+1)/2);
    cout<<ans<<endl;
  }
    
  
  }
  
   return 0;
}