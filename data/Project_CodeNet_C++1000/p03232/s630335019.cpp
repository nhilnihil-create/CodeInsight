#include<iostream>
#include<climits>
#include<vector>
#include<list>
#include<functional>
#include<algorithm>
#include<string>
#include<cmath>
#include<complex>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REP(i,n) for(int i=0;i<(n);i++)
#define INF (int)1e9
#define INFL (ll)1e11
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

const int p = 1000000007;

ll fac(int n) {
	if (n == 0) return 1;
	return n*fac(n - 1) % p;
}

ll pow(int a, int b) {
	if (b == 0) return 1;
	if (b % 2) return pow(a, b - 1)*a%p;
	ll tmp = pow(a, b / 2);
	tmp = tmp*tmp%p;
	return tmp;
}

ll inv(int a) {
	return pow(a, p - 2);
}

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N;
	cin >> N;
	vector<ll> A(N);
	vector<ll> sum(N + 1, 0);
	REP(i, N) {
		cin >> A[i];
		sum[i + 1] = (sum[i] + inv(i + 1)) % p;
		//cout << sum[i + 1] << "\n";
	}
	ll res = 0;
	REP(i, N) {
		ll tmp = (sum[N - i] + sum[i + 1] - sum[1]) % p;
		tmp = tmp*A[i] % p;
		res += tmp;
		res %= p;
	}
	res *= fac(N);
	res %= p;
	cout << res << "\n";

	return 0;
}