#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int N, K;
	cin >> N >> K;
	int basket[200000] = { 0 };
	for (int i = 0; i < N; i++) {
		int tmp;
		cin >> tmp;
		basket[tmp]++;
	}
	sort(basket, basket + N, greater<>());
	int sum = 0;
	for (int i = 0; i < K; i++) {
		sum += basket[i];
	}
	cout << N - sum << endl;
}