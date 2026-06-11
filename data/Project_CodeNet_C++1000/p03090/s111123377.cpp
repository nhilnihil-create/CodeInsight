#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin>>n;
  if(n%2==1){
    cout<<1LL*2*(n/2)*(n/2)<<endl;
    for(int i=1;i<n;i++){
      for(int j=i+1;j<n+1;j++){
        if(i+j!=n){
          cout<<i<<' '<<j<<endl;
        }
      }
    }
  }
  else {
    cout<<1LL*2*(n/2)*(n/2-1)<<endl;
    for(int i=1;i<n;i++){
      for(int j=i+1;j<n+1;j++){
        if(i+j!=n+1)cout<<i<<' '<<j<<endl;
      }
    }
  }
}
