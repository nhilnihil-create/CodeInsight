#include <bits/stdc++.h>

using namespace std;

int main() {
	int N; cin >> N;
	int p[N];
	// cin >> p[0];
	
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	sort(p, p+N);
	p[N-1] = p[N-1] / 2;
	long sum = 0;
	for (int i = 0; i < N; i++) {
		sum += p[i];
	}
	cout << sum;
	return 0;
}