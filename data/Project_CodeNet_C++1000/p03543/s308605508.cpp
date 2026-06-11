#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int one, ten, hun, tho;
  one = n % 10;
  ten = (n / 10) % 10;
  hun = (n / 100) % 10;
  tho = (n / 1000) % 10;
  
  if ((one == ten && ten == hun) || (ten == hun && hun == tho)) {
  	cout << "Yes" << endl;
  }
  else {
  	cout << "No" <<endl;
  }
}