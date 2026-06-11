#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  string n;
  cin>>a>>n;
  int red=0;
  int blue=0;
  
  for(int i=0;i<a;i++){
    if(n.at(i)=='R'){
      red++;
    }
    else{
      blue++;
    }
  }
  
  if(red>blue){
    cout<<"Yes"<<endl;
  }
  else{
    cout<<"No"<<endl;
  }
}