#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin>>X;
  for(int l=X;l>0;l--){
  for(int i=1;i<=35;i++){
    for(int j=2;j<10;j++){
      int test=pow(i,j);
      if(test==l){
        cout<<l<< endl;
        return 0;
      }
    }
  }
  }
}