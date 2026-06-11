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
  if(max(a,b) > 8) cout << ":(\n";
  else cout << "Yay!\n";
}