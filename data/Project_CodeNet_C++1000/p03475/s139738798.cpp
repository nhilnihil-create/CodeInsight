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
	vector<int> C(N - 1), S(N - 1), F(N - 1);
	for(int i = 0; i < N - 1; i++) cin >> C[i] >> S[i] >> F[i];
	int t = 0;
	for(int j = 0; j < N - 1; j++) {
		t = 0;
		for(int i = j; i < N - 1; i++) {
			if(t < S[i]) t = S[i];
			if(t % F[i] != 0) t += F[i] - (t % F[i]);
			t += C[i];
		}
		cout << t << endl;
	}
	cout << 0 << endl;
	return 0;
}
