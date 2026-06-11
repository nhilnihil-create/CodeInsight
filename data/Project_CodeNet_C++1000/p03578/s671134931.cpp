#include <iostream>
#include <map>
using namespace std;

int main() {
	int N, M;
	cin >> N;
	map<int, int> Probs;
	for (int i = 0; i < N; i++) {
		int d;
		cin >> d;
		Probs[d]++;
	}
	cin >> M;
	bool ans = true;
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		if (Probs.find(t) == Probs.end()) ans = false;
		else {
			if (Probs[t] == 0) ans = false;
			else Probs[t]--;
		}
	}
	cout << (ans ? "YES" : "NO") << endl;
}