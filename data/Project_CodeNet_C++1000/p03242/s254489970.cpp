#include<bits/stdc++.h>
using namespace std;
int main(){
  string a; cin>>a;
  if(a[0]=='1')a[0]='9';
  else if(a[0]=='9')a[0]='1';
  if(a[1]=='1')a[1]='9';
  else if(a[1]=='9')a[1]='1';
  if(a[2]=='1')a[2]='9';
  else if(a[2]=='9')a[2]='1';
  cout<<a<<endl;
  return 0;
}