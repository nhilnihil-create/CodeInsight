#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int money, highest;
  highest = 0;
  money = 0;
  for(int i = 0; i < n; i++){
    int p;
    cin >> p;
    money = money + p;
    if (highest < p) highest = p;
  }
  money = money - (highest/2);
  cout << money << endl;
}
