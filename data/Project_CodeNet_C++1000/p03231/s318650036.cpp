#include<bits/stdc++.h>
using namespace std;
int64_t gcd(int64_t x,int64_t y){
if(x==0 || y==0)
  return max(x,y);
  else{
   if(x<y)
     return gcd(x,y%x);
    else if(y<x)
      return gcd(y,x%y);
    else
      return x;
  
  }

}
int main(){
int64_t N,M;
  cin>>N>>M;
  string s,t;
  cin>>s>>t;
  int64_t g=gcd(N,M);
  bool x=true;
  for(int i=0;i<g;i++){
  if(s.at(i*(N/g))!=t.at(i*(M/g))){
     x=false; break;
  }
    
  }if(x)
    cout<<(N/g)*M<<endl;
  else
    cout<<-1<<endl;
  
   return 0;
}