#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int N, K, A[220000] = {}, Baket[220000] = {};
	int Ans = 0;

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}
	for (int i = 0; i < N; i++) {
		Baket[A[i]]++;
	}
	sort(Baket,Baket+N+1,greater<>());

	for (int i = 0; i < N-K; i++) {
		Ans += Baket[K + i];
	}
	cout << Ans << endl;

	return 0;
}