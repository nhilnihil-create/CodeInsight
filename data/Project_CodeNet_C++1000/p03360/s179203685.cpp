#include<bits/stdc++.h>
using namespace std;
int main(void) {
  int a,b,c,k,l;
  cin >> a >> b >> c;
  cin >> k;
  l = max({a,b,c});
  int  h = a + b + c - l;
  for(int i=0;i<k;++i) l = l * 2;
  cout << l + h << endl;
}

