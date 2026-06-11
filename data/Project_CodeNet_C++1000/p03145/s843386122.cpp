#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  int x=min(a*b/2,min(b*c/2,c*a/2));
  cout<<x<<endl;
}
