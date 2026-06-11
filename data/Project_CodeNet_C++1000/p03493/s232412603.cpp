#include <bits/stdc++.h>

using namespace std;

int main(){
	int inputNumber;
  	int count = 0;
  	cin >> inputNumber;
  
  	for (;inputNumber > 0; inputNumber /= 10) {
      	int single = inputNumber % 10;
    	if (single) {
        	count++;
        }
    }
  
  cout << count << endl;
}