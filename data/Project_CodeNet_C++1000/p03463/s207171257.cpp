#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  if((max(b,c)-min(c,b))%2==0)cout<<"Alice"<<endl;
  else if((max(c,b)-min(c,b))%2==1)cout<<"Borys"<<endl;
}