#include<bits/stdc++.h>
using namespace std;

int main(){
  int x,y;
  cin>>x>>y;
  int z;
  if((x-1)%(y-1)==0){
  z=(x-1)/(y-1);
  }
  else{
  z=(x-1)/(y-1)+1;
  }
  cout<<z<<endl;
}