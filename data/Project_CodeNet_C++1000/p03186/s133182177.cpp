#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  ll a,b,c;
  cin >>a >>b >>c;
  if(a+b+1>=c) cout << b+c << endl;
  else cout << b+(a+b+1) << endl;
  return 0;
}