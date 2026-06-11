#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
typedef pair<int, int>P;
const int INF = 1e15;
const int MOD = 1e9 + 7;
const double PI = 3.14159265358979323846;

signed main() {
	int N;
	cin >> N;
	vector<int>A(N), B(N), C;
	int asum = 0, bsum = 0, minussum = 0, cnt = 0;
	rep(i, N) {
		cin >> A[i];
		asum += A[i];
	}
	rep(i, N) {
		cin >> B[i];
		if (A[i] < B[i]) {
			minussum += B[i] - A[i];
			cnt++;
		}
		else if (A[i] > B[i]) {
			C.push_back(A[i] - B[i]);
		}
		bsum += B[i];
	}
	if (asum < bsum) {
		cout << -1;
		return 0;
	}
	sort(C.begin(), C.end());
	int i = C.size() - 1;
	while (1) {
		if (minussum <= 0) {
			cout << cnt;
			return 0;
		}
		minussum -= C[i];
		cnt++;
		i--;
	}
}