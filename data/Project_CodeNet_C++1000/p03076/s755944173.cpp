#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=1000000007;


int main() {
  int a,b,c,d,e;
  cin >> a;
  cin >> b;
  cin >> c;
  cin >> d;
  cin >> e;
  int m=10;
  if(a%10>0){
    m=min(a%10,m);
    a=(a/10+1)*10;
  }
  if(b%10>0){
    m=min(b%10,m);
    b=(b/10+1)*10;
  }
  if(c%10>0){
    m=min(c%10,m);
    c=(c/10+1)*10;
  }
  if(d%10>0){
    m=min(d%10,m);
    d=(d/10+1)*10;
  }
  if(e%10>0){
    m=min(e%10,m);
    e=(e/10+1)*10;
  }
  cout << a+b+c+d+e+m-10 << endl;
}