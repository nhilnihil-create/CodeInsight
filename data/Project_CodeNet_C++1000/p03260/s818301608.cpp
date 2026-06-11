#include <iostream>
#include <vector>
#include <cmath>
#include <string>
#include <algorithm>
#define rep(i, a, b) for(int i = a; i < b; i++)
#define ll long long
using namespace std;

int main() {
  int a, b;
  cin >> a >> b;
  if(a % 2 == 1 && b % 2 == 1) cout << "Yes\n";
  else cout << "No\n";
}