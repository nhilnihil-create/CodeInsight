#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if((abs(a-b) <= d && abs(b-c) <= d) || abs(a-c) <= d) cout << "Yes\n";
  else cout << "No\n";
}
