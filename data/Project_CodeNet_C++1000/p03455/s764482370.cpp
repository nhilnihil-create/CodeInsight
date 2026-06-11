#include <bits/stdc++.h>
using namespace std;

int main() {
  int a;
  int b;
  int c;
  cin >> a >> b;
  c = (a % 2) * (b % 2);
  if (c == 1){
    cout << "Odd" << endl;
  }
  if (c == 0){
    cout << "Even" << endl;
  }
}