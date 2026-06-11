#include <iostream>

using namespace std;

int dat[401];

int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= 200; i++) {
		for (int j = 1; i * j <= 200; j++) {
			dat[i * j]++;
		}
	}
	int count = 0;
	for (int i = 1; i <= n; i+=2)if (dat[i] == 8)count++;
	cout << count << endl;
}