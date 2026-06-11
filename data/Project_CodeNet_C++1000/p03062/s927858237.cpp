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
	for(int i = 0; i < N; i++) cin >> A[i];
	if(N == 2) {
		cout << abs(A[0] + A[1]) << endl;
		return 0;
	}
	int plus = 0, minus = 0, zero = 0;
	for(int i = 0; i < N; i++) {
		if(A[i] > 0) plus++;
		else if(A[i] == 0) zero++;
		else minus++;
	}
	sort(A.begin(), A.end());
	ll ans = 0;
	if(minus % 2 == 0) for(int i = 0; i < N; i++) ans += abs(A[i]);
	else if(minus == N) {
		for(int i = 0; i < N - 1; i++) ans += abs(A[i]);
		ans += A[N - 1];
	} 
	else {
		if(zero > 0) for(int i = 0; i < N; i++) ans += abs(A[i]);
		else {
			for(int i = 0; i < N; i++) {
				if(i < minus - 1) ans += abs(A[i]);
				else if(i == minus - 1) {
					if(abs(A[i]) > abs(A[i + 1])) ans += abs(A[i]) - abs(A[i + 1]);
					else ans += abs(A[i + 1]) - abs(A[i]);
				}
				else if(i == minus) continue;
				else ans += abs(A[i]);
			}
		}
	}
	cout << ans << endl;
	return 0;
}