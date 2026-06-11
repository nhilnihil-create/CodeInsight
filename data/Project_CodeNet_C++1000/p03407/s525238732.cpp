#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c;
  cin>>a>>b>>c;
  string s = "NoYes";
  cout<<(s.substr(2*(a+b>=c),2+(a+b>=c)));
}