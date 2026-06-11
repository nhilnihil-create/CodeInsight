#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	int K;
	int obj = 1;
	cin >> N >> K;
	
	for (int i = 0; i < N; i++) {
		if ((obj+K) <= (2*obj)) {
			obj += K;
		} else {
			obj *= 2;
		}
	}
	cout << obj << endl;
	
}
