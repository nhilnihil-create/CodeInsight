#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  for(int64_t i=1;i<=3500;i++){
    for(int64_t j=1;j<=3500;j++){
      if(4*i*j-n*j-i*n>0&&n*i*j%(4*i*j-n*j-i*n)==0){
        cout<<i<<' '<<j<<' '<<n*i*j/(4*i*j-n*j-i*n)<<endl;
        return 0;
      }
    }
  }
}