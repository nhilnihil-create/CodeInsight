#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

int main() {
	int a,b;
	cin >> a >> b;
	int sum = a + b;
	if(sum%2!=0){
		cout << (sum+1)/2 << endl;
	}
	else {
		cout << sum / 2 << endl;
	}
}