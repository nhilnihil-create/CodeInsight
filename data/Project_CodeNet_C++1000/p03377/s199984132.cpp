#include <bits/stdc++.h>
using namespace std;

int main() {
  int a,b,x;
  cin >>a>>b>>x;
  if(x>=a && x<a+b+1)
    cout << "YES" << endl;
  else 
    cout <<"NO" << endl;
}