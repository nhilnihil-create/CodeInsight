#include <bits/stdc++.h>
using namespace std;

int main() {
  int n,a,x;
  cin >> n >>a;
  x = n % 500;
  
  if (x == 0){
  cout << "Yes";
  }
  else {
    if (x <= a){
    cout << "Yes";
    }
    else {
    cout << "No";
    }
  }
}
