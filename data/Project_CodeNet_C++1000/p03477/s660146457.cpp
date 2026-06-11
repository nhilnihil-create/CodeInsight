#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define rep(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if(a+b < c+d) cout << "Right\n";
  else if(a+b > c+d) cout << "Left\n";
  else cout << "Balanced\n";
}