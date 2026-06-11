#include<iostream>
#include<cstdlib>
using namespace std;

int main() {
	int n;
	string temp;
	cin >> temp;
	n = temp.length();
	int ob = 0, ow = 0, eb = 0, ew = 0;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			if (temp[i] == '0') {
				eb++;
			}
			else {
				ew++;
			}
		}
		else {
			if (temp[i] == '0') {
				ob++;
			}
			else {
				ow++;
			}
		}
	}
	cout << min(ob + ew, ow + eb) << endl;
	return 0;
}