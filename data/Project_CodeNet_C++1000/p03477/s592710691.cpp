#include <bits/stdc++.h>
using namespace std;

int main() {
  int q,w,e,r;
  cin>>q>>w>>e>>r;
  if(q+w<e+r){
cout<<"Right"<<endl;
  }
else if(q+w==e+r){
cout<<"Balanced"<<endl;
}
else if(q+w>e+r){
cout<<"Left"<<endl;
}
}
    

  

