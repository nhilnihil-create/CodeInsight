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
	int N;
	cin >> N;
	vector<string> A(N*2);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
		A[i] = A[i] + A[i];
		A[i + N] = A[i];
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		bool flag = true;
		for (int j = 0; j < N; j++)for (int k = 0; k < N; k++) {
			if (A[j][i + k] != A[k][j+i])flag = false;
		}
		if (flag) ans += N;
	}
	cout << ans << endl;
}