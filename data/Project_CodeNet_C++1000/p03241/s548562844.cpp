#include<bits/stdc++.h>
using namespace std;
int main(){
int N,M;
  cin>>N>>M;
  int x=M/N;
  int ans;
  for(int i=x;0<i;i--){
  if(M%i==0){ans=i; break;}
  
  }cout<<ans<<endl;
    return 0;
}