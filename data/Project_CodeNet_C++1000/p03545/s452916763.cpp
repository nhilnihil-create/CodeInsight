#include<bits/stdc++.h>
using namespace std;
int main(){
  string g;
  cin>>g;
  int x,y,z,w,h,u,v,b;
  x=g.at(0)-'0';
  y=g.at(1)-'0';
  z=g.at(2)-'0';
  w=g.at(3)-'0';
  for(h=0;h<2;h++){
    for(u=0;u<2;u++){
      for(v=0;v<2;v++){
        b=x;
        if(h==0) b-=y; else b+=y;
        if(u==0) b-=z; else b+=z;
        if(v==0) b-=w; else b+=w;
        if(b==7){
          cout<<x;
          if(h==0) cout<<'-'; else cout<<'+';
          cout<<y;
          if(u==0) cout<<'-'; else cout<<'+';
          cout<<z;
          if(v==0) cout<<'-'; else cout<<'+';
          cout<<w<<"=7"<<endl;
          return 0;
        }
      }
    }
  }
}