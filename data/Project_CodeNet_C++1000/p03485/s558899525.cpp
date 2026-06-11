#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b;
  cin>>a>>b;
  int X;
  if(a%2==1 && b%2==0){
      a=a+1;
  }else if(a%2==0 && b%2==1){
      b=b+1;
  }
  X = (a+b)/2;
  cout<<X<<endl;

}