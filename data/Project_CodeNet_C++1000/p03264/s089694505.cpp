#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  
  int a,even,odd;
  cin >> a;
  
  even = a/2;
  if(a%2 == 0) odd = a/2;
  else odd = a/2 + 1;
  
  cout << even*odd << endl;
  
}
