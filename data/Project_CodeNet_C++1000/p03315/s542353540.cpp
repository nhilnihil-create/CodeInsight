#include<bits/stdc++.h>
using namespace std;
int main(){
  string z;
  int x=0;
  cin>>z;
  for(int y=0;y<4;y++){
    if(z.at(y)=='+') x++;
    else if(z.at(y)=='-') x--;
  }
  cout<<x<<endl;
}