#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  long long int y;
  cin>>n>>y;
  for(int i=0;i<=n;i++){
    for(int j=0;j<=n;j++){
      int t;
      if(n-i-j>=0) t=n-i-j;
      else continue;
        if(10000*i+5000*j+1000*t==y){
          cout<<i<<" "<<j<<" "<<n-i-j;
          return 0;
        }
    }
  }
  cout<<"-1"<<" "<<"-1"<<" "<<"-1";
}
