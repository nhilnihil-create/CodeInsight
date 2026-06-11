#include<bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >>N;
  int r=0;
  int m=N;

  while(m>0){
   r+=m%10;
   m/=10;
  }
 
   if(N%r==0) cout<<"Yes"<<endl;
   else cout<<"No"<<endl;
  
return 0;
}

