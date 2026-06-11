#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,d,e,f,g;
  cin>>a>>b>>c>>d;
  e=max(a,b)-min(a,b);
  f=max(a,c)-min(a,c);
  g=max(b,c)-min(b,c);
  if(f<=d) cout<<"Yes";
  else if(e<=d&&g<=d) cout<<"Yes";
  else cout<<"No";
}