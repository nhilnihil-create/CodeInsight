#include<iostream>
using namespace std;
int main(){

  int N;
  cin>>N;
  int A,B;
  cin>>A>>B;
  int ans=0;
  int sum=0;
  int k10000;
  int k1000;
  int k100;
  int k10;
  int k1;
  int i2;
  for(int i=1;i<=N;i++){
  
    i2=i;
    k10000=i2/10000;
    i2-=10000*k10000;
    k1000=i2/1000;
    i2-=1000*k1000;
    k100=i2/100;
    i2-=100*k100;
    k10=i2/10;
    i2-=10*k10;    
    k1=i2;
    sum=k10000+k1000+k100+k10+k1;
    if(A<=sum&&sum<=B)ans+=i;
  }
  cout<<ans;
  return 0; 
}