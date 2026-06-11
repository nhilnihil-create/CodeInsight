
// C - GCD on Blackboard

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
// const int INF = 2147483647;
// const ll INF = 9223372036854775807;
// const ll MOD = 1e9 + 7;

int A[100000];
int m_gcd[100000];
int m_gcd_l[100000];
int m_gcd_r[100000];

ll get_gcd(ll x, ll y) {
	if (y > 0) return get_gcd(y, x % y);
	else return x;
}

int main() {
	int N;
	cin >> N;

	for (int i=0; i<N; i++) {
		cin >> A[i];
	}

	int gcd;

	gcd = A[0];
	for (int i=1; i<N; i++) {
		m_gcd_l[i] = gcd;
		gcd = get_gcd(gcd, A[i]);
	}

	gcd = A[N-1];
	for (int i=N-2; i>=0; i--) {
		m_gcd_r[i] = gcd;
		gcd = get_gcd(gcd, A[i]);
	}

	for (int i=1; i<= N-2; i++) {
		m_gcd[i] = get_gcd(m_gcd_l[i], m_gcd_r[i]);
	}
	m_gcd[0] = m_gcd_r[0];
	m_gcd[N-1] = m_gcd_l[N-1];

	int ans = 0;

	for (int i=0; i<N; i++) {
		ans = max(ans, m_gcd[i]);
	}

	cout << ans << endl;

	return 0;
}