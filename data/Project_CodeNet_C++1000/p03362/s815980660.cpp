#include <iostream>
#include <vector>
using namespace std;
const int MAX = 55555;

bool P[MAX+1] = {false, false};
void sieve(int n) {
	fill(P+2, P+n+1, true);
	for (int i = 2; i*i <= n; ++i) {
		if (P[i]){
			for (int j = i*i; j <= n; j += i) {
				P[j] = false;
			}
		}
	}
}

int main() {
	int n;
	cin >> n;
	sieve(MAX);
	vector<int> ans;
	for (int i = 1; i <= MAX; i++) {
		if (P[i] && (i%5 == 1)) {
			ans.push_back(i);
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] << endl;
	}
	return 0;
}