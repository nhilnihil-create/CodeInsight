#include <bits/stdc++.h>
using namespace std;

int main() {
  int kazua=0;
  int kazub=0;
  int kazuc=0;
  int kazud=0;
  for(int i=0;i<6;i++){
    int a;
    cin >>a;
    if(a==1)kazua++;
    else if(a==2)kazub++;
    else if(a==3)kazuc++;
    else kazud++;
  }
  if(kazua>2||kazub>2||kazuc>2||kazud>2)cout<<"NO"<<endl;
  else cout<<"YES"<<endl;
  return 0;
}