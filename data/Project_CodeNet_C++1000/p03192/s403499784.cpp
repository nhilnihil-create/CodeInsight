#include<bits/stdc++.h> 
using namespace std;
int main(){
  char a[5];
  int b=0;
  cin>>a;
  for(int i=0;i<4;i++){
    if(a[i]=='2')
      b++;
  }
  cout<<b<<endl;
  return(0);
}