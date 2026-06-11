#pragma GCC optimize("O3")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target ("avx")
#include <bits/stdc++.h>
constexpr int INF = 2147483647;
constexpr long long int INF_LL = 9223372036854775807;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;


int main() {
	int A, B;
	cin >> A >> B;
	vector<string> g(100, string(100, '.'));
	for (int i = 0; i < 100; i++) {
		g[i][0] = '#';
	}
	for (int i = 0; i < 100; i++) {
		for (int j = 1; j < 99; j++) {
			if (i % 2 == 0)g[i][j] = '#';
		}
	}

	int a = 1, b = 1;
	for (int i = 1; i < 100 && a < A; i += 2) {
		for (int j = 2; j < 98 && a < A; j += 2) {
			g[i][j] = '#';
			a++;
		}
	}
	for (int i = 98; i >= 0 && b < B; i -= 2) {
		for (int j = 97; j >= 1 && b < B; j -= 2) {
			g[i][j] = '.';
			b++;
		}
	}

	cout << "100 100" << endl;
	for (int i = 0; i < 100; i++) {
		cout << g[i] << endl;
	}

	
}