#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  int counter=0;
  cin>>a>>b;
  for(a;a<=b;a++){
    if(a/10000==a%10&&(a%100)/10==(a%10000)/1000)
      counter++;
    else
      continue;
  }
  cout<<counter;
}