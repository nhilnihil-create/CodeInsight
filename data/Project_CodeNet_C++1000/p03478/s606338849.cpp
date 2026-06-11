#include <bits/stdc++.h>
using namespace std;

int sumdigits(int n){
  int d=0;
  
while(n>=1){
 
 d=d+n%10;
  n=n/10;
  
}
return d;
}

int main(){
  
  int N,A,B;
  int sum;
  
  int ans=0;
  cin>>N>>A>>B;
  
  for(int i=1;i<=N;i++){
  sum=sumdigits(i);
   if(A<=sum&&sum<=B){
    ans=ans+i;
    }  
  
  } 
   
    
  cout<<ans<<endl;
}
