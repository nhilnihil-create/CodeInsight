#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define all(a) (a).begin(), (a).end()
 
 
int main() {
  char X, Y;
  cin >> X >> Y;
  if(X < Y) cout << '<' << endl;
  else if(X == Y) cout << '=' << endl;
  else cout << '>' << endl;
}