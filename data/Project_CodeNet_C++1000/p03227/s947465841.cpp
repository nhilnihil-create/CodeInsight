#include<bits/stdc++.h>
using namespace std;
int main(){
  char a[10];
  cin>>a;
  if(strlen(a)==2)
    cout<<a<<endl;
  else
    cout<<a[2]<<a[1]<<a[0]<<endl;
  return(0);
}