#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int a, b, c;
  cin >> a >> b >> c;
  if(a <= c && a+b >= c) cout << "YES\n";
  else cout << "NO\n";
}
