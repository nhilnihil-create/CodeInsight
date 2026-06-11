#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,x,y;
  cin>>n>>x>>y;
  if(n>x+y)
    cout<<min(x,y)<<' '<<0<<endl;
  else
    cout<<min(x,y)<<' '<<x+y-n<<endl;
}