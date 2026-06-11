#include <bits/stdc++.h>
#define rep(i, n) for(int i= 0; i < (n); i++)
using ll= long long int;
using namespace std;
ll mod= 1e9 + 7;



int main() {
  int a,b;
  cin >> a>>b;
  if(a>=13){cout << b << endl; return 0;}
  if(a<=12 && a>=6){cout << b/2 << endl; return 0;}
  if(a<=5){cout << 0 << endl;}
}