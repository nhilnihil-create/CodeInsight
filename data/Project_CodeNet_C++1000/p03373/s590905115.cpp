#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int a,b,c,x,y,p,min=INT_MAX;
  cin >>a >>b >>c >>x >>y;
  for(int i=0; i<100001; ++i) {
    p = 2*c*i + a*max(0,x-i) + b*max(0,y-i);
    if(min>p) min=p;
  }
  cout << min << endl;
}