#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  int a,b,c;
  cin >>a >>b >>c;
  if(a==b) cout << c << endl;
  if(a==c) cout << b << endl;
  if(b==c) cout << a << endl; 
  return 0;
}