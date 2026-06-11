#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,x; cin>>a>>b;
  x=max(a,b)*2;
  if(a!=b) x--;
  cout<<x<<endl;
}