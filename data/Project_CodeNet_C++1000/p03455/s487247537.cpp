#include <bits/stdc++.h>
using namespace std;

int main(){
  int a, b;cin >> a >> b;
  bool ok = false;
  ok |= (~a & 1);
  ok |= (~b & 1);
  cout << (ok ? "Even" : "Odd") << endl;
}