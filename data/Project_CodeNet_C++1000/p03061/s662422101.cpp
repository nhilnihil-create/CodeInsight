#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef vector<vector<int>> Graph;
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
#define pi 3.14159265359
#define inf 2147483647
#define INF 9223372036854775807
#define mod 1000000007
#define mod2 998244353

int gcd(int n, int m) {
	if(n < m) swap(n, m);
	if(n % m == 0) return m;
	return gcd(m, n % m);
}

int lcm(int n, int m) {
	return n * m / gcd(n, m);
}

int main() {
	int N; cin >> N;
	vector<int> A(N);
	for(int i = 0; i < N; i++) cin >> A[i];
	vector<int> left(N), right(N);
	for(int i = 0; i < N; i++) {
		if(i == 0) {
			left[0] = A[0];
			continue;
		}
		left[i] = gcd(left[i - 1], A[i]);
	}
	for(int i = N - 1; i >= 0; i--) {
		if(i == N - 1) {
			right[N - 1] = A[N - 1];
			continue;
		}
		right[i] = gcd(right[i + 1], A[i]);
	}
	int M = 0; 
	for(int i = 0; i < N; i++) {
		int G;
		if(i == 0) G = right[1];
		else if(i == N - 1) G = left[N - 2];
		else G = gcd(left[i - 1], right[i + 1]);
		M = max(M, G);
	}
	cout << M << endl;
	return 0;
}
