#include<iostream>

using namespace std;

int main() {
	int N, A, remainder;
	cin >> N >> A;
	remainder = N % 500;
	if (remainder <= A) {
		printf("Yes");
	}
	else {
		printf("No");
	}


	return 0;
}