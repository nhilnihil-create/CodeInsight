#include <bits/stdc++.h>
using namespace std;
//A - Parking
int main() {
  int n, a, b;
  cin >> n >> a >> b;
  int price1 = n*a;
  int price2 = b;
  
  if (price1 <= price2)
    cout << price1 << endl;
  else
    cout << price2 << endl;
}
