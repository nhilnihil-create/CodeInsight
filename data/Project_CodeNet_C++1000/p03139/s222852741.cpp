#include<bits/stdc++.h>
using namespace std;


int main(){
  int n,a,b;
  cin >> n >> a >> b;
  int x=min(a,b);
  int y=(a+b)-n;
  if(y<0)y=0;
  cout << x << " " << y << endl;
  return 0;
}
