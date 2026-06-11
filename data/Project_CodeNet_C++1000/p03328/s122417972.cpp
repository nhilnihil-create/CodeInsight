#include<iostream>
 
using namespace std;
 
int main() {
	int a, b;
	cin >> a >> b;
 
	int diff = b - a;
 
	int tower_a = 0;
	//int tower_b = 0;
	for (int i = 1; i <= diff; i++) {
		if (i < diff) {
			tower_a += i;
		}
		//tower_b += i;
	}
 
	//cout << tower_a << " " << tower_b << endl;
	cout << tower_a - a << endl;
 
}