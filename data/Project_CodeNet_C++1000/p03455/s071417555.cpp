#include <bits/stdc++.h>
using namespace std;

int main() {
  int a = 0, b = 0;
  cin >> a >> b;
  int ans = a * b;
  if( ans % 2 == 1){
    cout << "Odd" << endl;
  }
  else{
    cout << "Even" << endl;
  }
}