#include <bits/stdc++.h>
using namespace std;
int main(){
  int a,b,l,m,n;
  cin >> a >> b;
  l=a*2-1;
  m=a+b;
  n=b*2-1;
  cout << max(l,max(m,n)) << endl;
}