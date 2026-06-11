#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z,w;
  cin>>x>>y>>z;
  if(y-x+1<=2*z){
    for(w=x;w<=y;w++){
      cout<<w;
      if(w<y) cout<<' ';
      else cout<<endl;
    }
  }
  else{
    for(w=0;w<z;w++) cout<<x+w<<' ';
    for(w=z-1;w>=0;w--){
      cout<<y-w;
      if(w>0) cout<<' ';
      else cout<<endl;
    }
  }
}