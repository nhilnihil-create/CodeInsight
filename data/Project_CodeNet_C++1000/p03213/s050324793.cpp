#include <iostream>
#include <vector>
using namespace std;
const int N_MAX = 100;

bool P[N_MAX+1] = {false, false};

void sieve(int n) {
	fill(P+2, P+n+1, true);
	for (int i = 2; (long long)i*i <= n; ++i) {
		if (P[i]){
			for (int j = i*i; j <= n; j += i) {
				P[j] = false;
			}
		}
	}
}

vector<pair<int,int>> prime_factorization_factorial(int n) {
	vector<pair<int, int>> v;
	for (int i = 2; i <= n; i++) {
		if (!P[i]) continue;
		int p = i, e = 0;
		while (p <= n) {
			e += n / p;
			p *= i;
		}
		v.emplace_back(i, e);
	}
	return v;
}

int main() {
	sieve(100);
	int n;
	cin >> n;
	int s[150] = {0};
	auto v = prime_factorization_factorial(n);
	for (auto e : v) {
		s[e.second]++;
	}
	for (int i = 148; i >= 1; i--) {
		s[i] += s[i+1];
	}
	int ans = 0;
	ans += s[4] * (s[4] - 1) / 2 * (s[2] - 2);
	ans += s[14] * (s[4] - 1);
	ans += s[24] * (s[2] - 1);
	ans += s[74];
	cout << ans << endl;
	return 0;
}