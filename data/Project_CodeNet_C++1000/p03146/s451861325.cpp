#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i< (n);i++)
using namespace std;

int main() {
  int s;
  cin>>s;
  int d[1000010];
  d[0]=s;
  rep(i,1000000){
  if(d[i]%2==0)d[i+1]=d[i]/2;
   else{ d[i+1]=d[i]*3+1;}            
  }
  
  bool ok=false;
  for(int i=1;i<1000000;i++){
   for(int j=i-1;j>=0;j--){
     if(d[i]==d[j]){
       cout<<i+1<<endl;
       ok=true;
       break;
     }
    if(ok)break;
   }
  } 
    
         
}
