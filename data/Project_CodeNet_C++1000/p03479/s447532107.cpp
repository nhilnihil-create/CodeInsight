#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x,y,c=1; cin>>x>>y;
  while(x*2<=y) c++,x*=2;
  cout<<c<<endl;
}