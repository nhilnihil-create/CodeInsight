#include<bits/stdc++.h>
using namespace std;
int main(){
  int a,b,c,d;
  cin >> a>>b>>c>>d;
  int p=abs(b-a);
  int q=abs(c-b);
  int u=abs(c-a);
  string s="No";
  if(p<=d && q<=d){
    s="Yes";
  }
  if(u<=d){
    s="Yes";
  }
  cout << s;
}