#include <bits/stdc++.h>
using namespace std;

int main() {
	int N, M;
	map<int,int> D;
	cin >> N;
	for (int i = 0; i < N; i++) {
		int d;
		cin >> d;
		D[d]++;
	}
	string ans = "YES";
	cin >> M;
	for (int i = 0; i < M; i++) {
		int t;
		cin >> t;
		D[t]--;
		if (D[t] < 0) {
			ans = "NO";
			break;
		}
	}
	cout << ans << endl;
	return 0;
}
