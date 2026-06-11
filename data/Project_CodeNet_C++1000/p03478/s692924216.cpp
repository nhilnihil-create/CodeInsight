#include<iostream>

using namespace std;


int main() {
	int N, A, B;
	int sum = 0;
	cin >> N >> A >> B;
	
	for (int i = 1; i <= N; i++) {
		int j = i;
		int remainder = 0;
		while (j != 0) {
			remainder += j % 10;
			j /= 10;
		}
		if (A <= remainder && remainder <= B) {
			sum += i;
		}
	}
	cout << sum << endl;


	return 0;
}
