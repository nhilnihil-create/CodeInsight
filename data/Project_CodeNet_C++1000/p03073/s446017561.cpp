#include<iostream>
using namespace std;
int main() {
	
	//C
	string s;
	int i;
	int counter1 = 0, counter2 = 0;
	cin >> s;
	for (i = 0; i < s.size(); i++) {

		if (i % 2 == 0) {
			if (s[i] == '1') {
				counter1++;
				//cout << 'a';
			}
			else {
				counter2++;
				//cout << 'i';
			}
		}
		else {
			if (s[i] == '0') {
				counter1++;
				//cout << 'u';
			}
			else {
				counter2++;
				//cout << 'e';
			}
		}
		
	}

	if (counter1 < counter2) {
		cout << counter1 << endl;
	}
	else {
		cout << counter2 << endl;
	}

	return 0;
	//B
	/*int n;
	cin >> n;
	int i;
	int h[20];
	for (i = 0; i < n; i++) {
		cin >> h[i];
	}
	int maxh = 0;
	int hcounter = 0;
	maxh = h[0];
	hcounter++;
	for (i = 1; i < n; i++) {
		if (h[i] >= maxh) {
			maxh = h[i];
			hcounter++;
		}
	}
	cout << hcounter << endl;
	return 0;*/
	
	
	//A
	/*
	int a,b;
	cin >> a >> b;
	int x = 0;
	for (int i = 0; i < 2; i++) {
		if (a > b) {
			x = x + a;
			a--;
		}
		else {
			x = x + b;
			b--;
		}
	}
	cout << x << endl;
	return 0;
	*/


}