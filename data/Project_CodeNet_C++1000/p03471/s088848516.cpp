#include<bits/stdc++.h>
using namespace std;
int main(){
  int z,y,x,w;
  cin>>z>>y;
  y/=1000;
  for(x=0;x<=z;x++){
    for(w=0;w<=z-x;w++){
      if(10*x+5*w+z-x-w==y){
        cout<<x<<' '<<w<<' '<<z-x-w<<endl;
        return 0;
      }
    }
  }
  cout<<"-1 -1 -1"<<endl;
}