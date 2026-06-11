#include <bits/stdc++.h>
using namespace std;
 
int main() {
  string a;
  cin >> a;
  int ttl = 0;
  for (char &c : a) {
    ttl += (int)(c - '0');
  }
  cout << ttl << endl;
}