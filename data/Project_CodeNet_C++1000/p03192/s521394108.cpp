#include <bits/stdc++.h>
using namespace std;

int main() {
	string N;
	cin >> N;
	int count = 0;
	for (char x : N) {
		if (x == '2') {
			count++;
		}
	}
	cout << count << endl;
}