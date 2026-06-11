#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int a,b,c,k;
  cin >> a >> b >> c >> k;
  long long x=max(a,max(b,c));
  a-=x;
  for(int i=0;i<k;i++) x*=2;
  cout << a+b+c+x << endl;
}