#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int fx = 0, k = n;

  
  while (k > 0) {
    fx += k % 10;
    k /= 10;
  }
  
  if (n % fx == 0) 
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
}
