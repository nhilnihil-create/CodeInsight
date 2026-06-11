#include <bits/stdc++.h>
using namespace std;

int main() {
  int X;
  cin>>X;
  bool ans=false;
  for(int i=X;i>0;i--){
    for(int j=1;j<35;j++){
      for(int l=2;l<10;l++){
        int test=pow(j,l);
        if(test==i){
          cout<<i<< endl;
          return 0;
        }
      }
    }
  }
}
