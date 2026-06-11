#include <bits/stdc++.h>
using namespace std;
 
int main() {
  long long N;
  cin>>N;
  long long w=0;
  long long h=0;
  long long n=0;
  for(long long i=1;i<=3500;i++){
    for(long long j=1;j<=3500;j++){
   if((4*i*j-N*i-N*j)> 0 && (N*i*j) % (4*i*j-N*i-N*j)==0 && (N*i*j) / (4*i*j-N*i-N*j)>=1  ){
     w=(N*i*j) / (4*i*j-N*i-N*j);
     h=i;
    n=j; 
   }
   
    
    
    
    }
  }
  cout <<h<<" "<<n<<" "<<w<<endl;
 }
