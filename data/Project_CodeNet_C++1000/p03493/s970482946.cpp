#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#define ll long long
#define rep(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
using namespace std;

int main() {
  string s;
  cin >> s;
  int n = 0;
  rep(i, 0, 3) {
    if(s[i] == '1') n++;
  }
  cout << n << "\n";
}
