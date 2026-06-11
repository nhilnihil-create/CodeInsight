#include <bits/stdc++.h>
using namespace std;

int main(){
  int s;
  cin>>s;
  if(s==2 || s==1){
    cout<<4<<endl;
    return 0;
  }
  int i=4;
  while(s!=4){
    if(s%2==0)
      s/=2;
    else
      s=s*3+1;
    i++;
  }
  cout<<i<<endl;
}