#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
const double PI = 3.14159265358979323846;

int main() {
  string n;
  cin >> n;
  rep(i, 3) {
    if(n[i] == '9') n[i] = '1';
    else if(n[i] == '1') n[i] = '9';
  }
  rep(i, 3) cout << n[i];
  cout << endl;
}