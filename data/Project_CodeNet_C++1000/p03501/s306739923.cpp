#include <bits/stdc++.h>
using namespace std;

int main() {
  int a, b, c;
  cin >> a  >> b >> c;
  int plan1 = a * b;
  int plan2 = c;
  if (plan1 <= plan2) {
    cout << plan1;
  }else{
  	cout << plan2;
  }
}