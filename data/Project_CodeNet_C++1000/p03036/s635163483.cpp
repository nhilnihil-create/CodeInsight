#include <bits/stdc++.h>
using namespace std;

int main(){
  int r,D,Xo;cin>>r>>D>>Xo;
  int X=Xo;
  for(int i=1;i<=10;i++){
    X=r*X-D;
    cout<<X<<endl;
  }
}
