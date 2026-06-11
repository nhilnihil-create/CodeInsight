#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
#define ll long long
#define all(V) V.begin(), V.end()

vector<int> rea(100000, 0);

int main() {
	int K, a, b, c;
	cin >> K;
	rea[1] = 1;
	queue<int> Q;
	Q.push(1);
	while (!Q.empty()) {
		a = Q.front();
		Q.pop();

		b = (a * 10) % K;
		if (rea[b] == 0 || rea[b] > rea[a]) {
			rea[b] = rea[a];
			Q.push(b);
		}
		if (a % 10 != 9) {
			c = (a + 1) % K;
			if (rea[c] == 0 || rea[c] > rea[a] + 1) {
				rea[c] = rea[a] + 1;
				Q.push(c);
			}
		}
	}
	cout << rea[0] << endl;
}