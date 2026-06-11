#include <bits/stdc++.h>
using namespace std;


int main() {

  int a,b;
  cin>>a>>b;


  bool flg=false;
  for(int c=1;c<=3;c++){
    if(a*b*c%2!=0)
      flg=true;
  }

  if(flg)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

  return 0;
}


