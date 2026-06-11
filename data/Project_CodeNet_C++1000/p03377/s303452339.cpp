#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
 
int main() {
  ios::sync_with_stdio(0); 
  cin.tie(0); 
  
  int a, b, x;
  cin >> a >> b >> x;
 
  if (a <= x && b > x - a) cout << "YES" << "\n";
  else cout << "NO" << "\n";
}
