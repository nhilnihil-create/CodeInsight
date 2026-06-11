#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d,l,r;
  cin>>a>>b>>c>>d;
  l=a+b; r=c+d;
  if(l>r){
    printf("Left");
  }
  else if(l<r){
    printf("Right");
  }else{
    printf("Balanced");
  }
  return 0;
}