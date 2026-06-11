#include <bits/stdc++.h>
using namespace std;

int main() {
	int N; int A; int B;
	cin >> N >> A >> B;

	int max = min(A, B);
	int min = 0;
	if ((A + B) - N > 0) {
		min = (A + B) - N;
	}

	cout << max << " " << min << endl;
}