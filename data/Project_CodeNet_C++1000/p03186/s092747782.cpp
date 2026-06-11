#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  int kotae=b+min(a+b,c);
  if(a+b<c)kotae++;
  cout<<kotae<<endl;
  return 0;
}