#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c;
  	cin >> a;
  	c = a % 10;
  	b = (a % 100) / 10;
  	a = a / 100;
  	cout << a + b + c << endl;
}
