#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  int a=0,b,c,d,e=0,f;
  cin >>a>>b;
  c=a+b,d=a*b;
  if(c==15) cout <<"+\n";
  else{
    if(d==15) cout <<"*\n";
    else cout <<"x\n";
  }
  return 0;
}
