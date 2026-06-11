#include <bits/stdc++.h>
using namespace std;

int main(){
	int a, b, c, d;
  	int inputNumber;
  	cin >> inputNumber;
  
  	d = inputNumber % 10;
  	inputNumber /= 10;
  	c = inputNumber % 10;
  	inputNumber /= 10;
  	b = inputNumber % 10;
  	inputNumber /= 10;
  	a = inputNumber;

  
  	if (b != c) {
    	cout << "No" << endl;
    } else if (a != b) {
    	if (c != d) {
        	cout << "No" << endl;
        } else {
        	cout << "Yes" << endl;
        }
    } else {
    	cout << "Yes" << endl;
    }
}