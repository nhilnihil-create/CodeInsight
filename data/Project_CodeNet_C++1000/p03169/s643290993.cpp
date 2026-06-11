#include <bits/stdc++.h>
using namespace std;
#define PI 3.14159265358979323
#define ll long long int
#define ld double
#define vi vector <int>
#define vl vector <ll>
#define all(v) (v).begin(),(v).end()
#define pb push_back
#define MOD 1000000007
ll power(ll a, ll b) { //a^b
	ll res = 1;
	a = a % MOD;
	while (b > 0) {
		if (b & 1) {res = (res * a) % MOD; b--;}
		a = (a * a) % MOD;
		b >>= 1;
	}
	return res;
}

ll gcd(ll a, ll b) {return (b == 0) ? a : gcd(b, a % b);}

ld dp[301][301][301];
ld prob[301][301][301];

int main() {
#ifndef ONLINE_JUDGE
	// for getting input from input.txt
	freopen("input.txt", "r", stdin);
	// for writing output to output.txt
	freopen("output.txt", "w", stdout);
#endif
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	ll n;
	cin >> n;
	vl a(n);
	vl cnt(4, 0);
	for (ll i = 0; i < n; i++) {
		cin >> a[i];
		cnt[a[i]]++;
	}
	prob[cnt[1]][cnt[2]][cnt[3]] = 1;
	for (ll k = n; k >= 0; k--) {
		for (ll j = n; j >= 0; j--) {
			for (ll i = n; i >= 0; i--) {
				if (i + j + k == 0 || i + j + k > n)
					continue;
				ld was = (n - i - j - k) * 1.0 / n;
				was = was / (1 - was);
				ld move = (was + 1) * prob[i][j][k];
				dp[i][j][k] += move;
				if (i) {
					prob[i - 1][j][k] += prob[i][j][k] * (i * 1.0 / (i + j + k));
					dp[i - 1][j][k] += dp[i][j][k] * (i * 1.0 / (i + k + j));
				}
				if (j) {
					prob[i + 1][j - 1][k] += prob[i][j][k] * (j * 1.0 / (i + j + k));
					dp[i + 1][j - 1][k] += dp[i][j][k] * (j * 1.0 / (i + k + j));
				}
				if (k) {
					prob[i][j + 1][k - 1] += prob[i][j][k] * (k * 1.0 / (i + j + k));
					dp[i][j + 1][k - 1] += dp[i][j][k] * (k * 1.0 / (i + k + j));
				}
			}

		}
	}
	printf("%0.10lf\n", dp[0][0][0]);
}
