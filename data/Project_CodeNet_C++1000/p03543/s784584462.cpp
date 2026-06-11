#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int n;
  cin >> n;

  int onesPlace = n % 10;
  n /= 10;
  int tensPlace = n % 10;
  n /= 10;
  int hundredsPlace = n % 10;
  n /= 10;
  int thousandsPlace = n;
  
  if (tensPlace == hundredsPlace && (tensPlace == onesPlace || hundredsPlace == thousandsPlace))
  {
    cout << "Yes";
  }
  else
  {
    cout << "No";
  }
}