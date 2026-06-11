#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b;
  cin>>a>>b;
  int x=max(a+b,max(a-b,a*b));
  cout<<x;
}