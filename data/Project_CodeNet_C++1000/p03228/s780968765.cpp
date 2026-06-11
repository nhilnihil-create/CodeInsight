#include<bits/stdc++.h>
#define int long long 
using namespace std;
signed main(){
  int a,b,k;
  cin>>a>>b>>k;
  for(int i=1;i<=k;i++){
    if(a%2!=0){
      a--;
    }
    b += a / 2;
    a = a / 2;
    i++;
    if(i>k){
      break;
    }else{
    if(b%2!=0){
      b--;
    }
    a += b / 2;
    b = b / 2;
    }
  }
  cout<<a<<" "<<b<<"\n";
  return(0);
}
