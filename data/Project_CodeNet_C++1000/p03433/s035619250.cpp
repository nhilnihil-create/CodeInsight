#include <bits/stdc++.h>
using namespace std;

int main() {
  int yenSum, yen1;
  cin >> yenSum >> yen1;
  
  if (yenSum % 500 <= yen1) {
    cout << "Yes" << endl;
  }else{
    cout << "No" << endl;
  }
}