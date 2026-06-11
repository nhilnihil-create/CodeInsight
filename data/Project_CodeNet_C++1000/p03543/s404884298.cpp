#include <bits/stdc++.h>
using namespace std;

int main() {
 int n;
 cin >> n;
 int c1 = n / 1000;
 int c2 = n % 1000 / 100;
 int c3 = n % 100 / 10;
 int c4 = n % 10;
 if((c1 == c2 && c2 == c3) || (c2 == c3 && c3 == c4)){
  cout << "Yes" << endl;
 } else {
  cout << "No" << endl;
 }
}