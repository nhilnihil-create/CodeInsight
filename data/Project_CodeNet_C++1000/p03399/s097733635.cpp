#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  
  int a,b,c,d;
  cin >> a >> b >> c >> d;
  int sum = 0;
  
  if(a < b) sum += a;
  else sum += b;
  
  if(c < d) sum += c;
  else sum += d;
  
  cout << sum << endl;
  
}
