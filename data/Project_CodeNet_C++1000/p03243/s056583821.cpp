#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  ll n; cin >> n;
  if(n<=111) cout << 111 << endl;
  if(n>111 && n<=222) cout << 222 << endl;
  if(n>222 && n<=333) cout << 333 << endl;
  if(n>333 && n<=444) cout << 444 << endl;
  if(n>444 && n<=555) cout << 555 << endl;
  if(n>555 && n<=666) cout << 666 << endl;
  if(n>666 && n<=777) cout << 777 << endl;
  if(n>777 && n<=888) cout << 888 << endl;
  if(n>888) cout << 999 << endl;
  
  return 0;
}