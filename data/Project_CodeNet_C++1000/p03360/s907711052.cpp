#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < n; i++) 
using namespace std;
typedef long long ll;

int main() {
  
  int a, b, c, k;
  cin >> a >> b >> c >> k;
  
  if (a < b) swap(a,b);
  if (a < c) swap(a,c);
  
  int ans = a * pow(2,k) + b + c;
  
  cout << ans << endl;
}