#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  char b;
  cin >> b;
  if(b == 'A') cout << 'T' << endl;
  else if(b == 'T') cout << 'A' << endl;
  else if(b == 'C') cout << 'G' << endl;
  else cout << 'C' << endl;
}