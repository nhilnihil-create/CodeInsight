#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#define ll long long
#define rep(i, a, b) for(int i = a; i < b; i++)
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if(a*b % 2 == 0) cout << "Even\n";
  else cout << "Odd\n";
}
