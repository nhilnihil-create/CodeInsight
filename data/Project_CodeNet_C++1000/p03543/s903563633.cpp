#include <bits/stdc++.h>
using namespace std;

int main() {
  	int n, a, b, c, d;
  	cin >> n;
  	a = n / 1000; // 7777 / 1000 = 7 
  	b = n % 1000 / 100;
  	c = n % 1000 % 100 / 10;
    d = n % 1000 % 100 % 10;
    /* 1118  1125
       8111
       1111
       それ以外　*/
  	if (a == b) {
      if (b == c) {
      cout << "Yes" << endl;
      }
      else {
      cout << "No" << endl;
      }
    }
 	 else if (b == c) {
       if (c == d) {
       cout << "Yes" << endl;
       }
       else {
       cout << "No" << endl;
       }
	}
  	else {
      cout << "No" << endl;
    }
}