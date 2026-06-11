#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,z,w,v=0,u,q;
  cin>>x>>y>>z;
  for(w=1;w<=x;w++){
    u=w;
    q=0;
    while(u>0){
      q+=u%10;
      u/=10;
    }
    if(y<=q&&q<=z) v+=w;
  }
  cout<<v<<endl;
}