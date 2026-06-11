#include <bits/stdc++.h>
using namespace std;

int main() {
  int A;
  cin >> A;
  if (A%2 == 0)
    cout << (A/2)*(A/2) << endl;
  else
    cout << ((A-1)/2)*((A-1)/2 + 1) << endl;
  
}
