#include <bits/stdc++.h>
using namespace std;

long long X, Y, total=0;

int main () {
  cin >> X >> Y;
  while (X<=Y) {
    X=X*2;
    total++;
  }
  cout << total << endl;
}