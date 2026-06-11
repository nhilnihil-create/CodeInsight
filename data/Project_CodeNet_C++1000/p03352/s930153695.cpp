#include<bits/stdc++.h>
using namespace std;
int main(){
  int x;
  cin>>x;
  for(;x>=1;x--){
    int n=x;
    if(x==1)
      cout<<x<<endl;
    for(int j=2;j*j<=n;j++){
      while(n%j==0)
        n/=j;
      if(n==1){
        cout<<x<<endl;
        x=1;
      }
      n=x;
    }
  }
}