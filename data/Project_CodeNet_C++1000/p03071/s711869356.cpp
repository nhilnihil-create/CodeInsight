#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;
using ll = long long;
int main(void){
  int A,B;
  cin>>A>>B;
  
  int sum=0;
  rep(i,2){
     if(A>B){
         sum+=A;
         A--;
     }
     else{
         sum+=B;
         B--;
     }
  }
  cout<<sum<<endl;
  
}