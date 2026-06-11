#include <bits/stdc++.h>
using namespace std;

int main(){
  double heikin;
  int heikin2;
  double a, b;
  cin>>a>>b;
  heikin=(a+b)/2;
  heikin2=(a+b)/2;
  if(heikin-heikin2==0){
    cout<<heikin2<<endl;
  }
  else{
    cout<<heikin2+1<<endl;
  }
}
