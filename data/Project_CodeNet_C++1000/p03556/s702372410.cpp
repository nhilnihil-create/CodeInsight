#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int i = 1;

	while (i * i <= N) {
		i++;
	}

	cout << (i - 1) * (i - 1) << endl;
}