#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int, int>;
const int INF = 1e9;
const int dx[] = {-1,0,1,0};
const int dy[] = {0,-1,0,1};
#define PI 3.14159265358979323846264338327950L
#define MOD 1000000007
//setprecision(15)

int main() {
	int N, M, C; cin >> N >> M >> C;
	int B[20]; rep(i, M) cin >> B[i];
	int ans = 0;
	rep(i, N) {
		int sum = 0;
		rep(j, M) {
			int tmp; cin >> tmp;
			sum += tmp * B[j];
		}
		sum += C;
		if (sum > 0) ans++;
	}
	cout << ans << endl;
}