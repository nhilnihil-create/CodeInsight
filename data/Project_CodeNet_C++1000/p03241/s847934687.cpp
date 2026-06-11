#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) {

  if(a < b) return gcd(b, a);
     if (b == 0) return a;
    else return gcd(b, a % b);
}


int main(){
  int N,M;
  cin>>N>>M;
  if(N==1){
    cout<<M<<endl;
    return 0;
  }
  if(N==2){
    int ans=0;
    for(int i=1;i<=M/2+1;i++){
      ans=max(ans,gcd(i,M-i));
    }
    cout<<ans<<endl;
    return 0;
  }
    
  while(N<=M/2){
    if(M%N==0){
      cout<<M/N<<endl;
      return 0;
    }
    N++;
  }
  cout<<1<<endl;
  return 0;
}
