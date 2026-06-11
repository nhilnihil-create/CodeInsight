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

int main() {
	int N; cin >> N;
	vector<ll> A(N);
	ll S = 0, m = INF;
	int minus = 0, zero = 0;
	for(int i = 0; i < N; i++) {
		cin >> A[i];
		S += abs(A[i]);
		if(A[i] < 0) minus++;
		else if(A[i] == 0) zero++;
		m = min(m, abs(A[i]));
	}
	if(zero != 0 || minus % 2 == 0) {
		cout << S << endl;
		return 0;
	}
	else {
		cout << S - 2 * m << endl;
		return 0;
	}
}
