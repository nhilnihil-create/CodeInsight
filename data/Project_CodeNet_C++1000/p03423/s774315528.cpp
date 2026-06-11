#include<iostream>
using namespace std;

int main() {
	int N;
	cin >> N;

	int answer = 0;
	int i = N;

	while (i >= 3) {
		i -= 3;
		answer++;
	}

	cout << answer << endl;
}