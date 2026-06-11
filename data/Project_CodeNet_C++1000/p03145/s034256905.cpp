#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,c;
  cin >>a>>b>>c;
  int dai=max({a,b,c});
  int shou=min({a,b,c});
  int naka=a+b+c-dai-shou;
  int kotae=(shou*naka)/2;
  cout<<kotae<<endl;
  return 0;
}