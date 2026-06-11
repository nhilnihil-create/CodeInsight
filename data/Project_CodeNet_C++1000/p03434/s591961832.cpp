#include<iostream>
#include<algorithm>
#include <functional>

using namespace std;


int main() {
	int N;
	int a[101];
	int Alice = 0;
	int Bob = 0;

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	sort(a, a + N, greater<int>());
	
	for (int i = 0; i < N; i += 2) {
		Alice += a[i];
	}
	for (int i = 1; i < N; i += 2) {
		Bob += a[i];
	}

	printf("%d", Alice - Bob);


	return 0;
}