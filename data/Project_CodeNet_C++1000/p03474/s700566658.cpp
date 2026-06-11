#include<bits/stdc++.h>
using namespace std;
int main(){
  int x,y,v;
  string z,w="Yes";
  cin>>x>>y>>z;
  for(v=0;v<x+y+1;v++){
    if(v==x&&z.at(v)!='-'){w="No";break;}
    else if(v!=x&&z.at(v)=='-'){w="No";break;}
  }
  cout<<w<<endl;
}