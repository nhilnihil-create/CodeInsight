#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin>>a>>b>>c;
  if(a<(b+c)){
    cout<<min(b,c)<<' '<<(b+c)-a<<endl;
  }
  else{
    cout<<min(b,c)<<' '<<0<<endl;
  }
}