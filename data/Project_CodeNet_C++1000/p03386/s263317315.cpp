#include <iostream>
#include <set>
using namespace std;

int main() {
	int A, B, K;
	cin >> A >> B >> K;
	set<int> s;
	for (int i = 0; i < K; i++) {
		if (i > (B - A)) break;
		s.insert(A + i);
		s.insert(B - i);
	}

	for (auto x : s) {
		cout << x << endl;
	}
}