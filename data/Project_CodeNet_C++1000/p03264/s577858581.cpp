#include <bits/stdc++.h>
using namespace std;
int main() {
  int a;
  cin >> a;
  if (a%2 == 0) {
    int t = a/2;
    cout << t*t << endl;
  } else {
    int t = (a-1)/2;
    int u = a-t;
    cout << t*u << endl;
  }
}