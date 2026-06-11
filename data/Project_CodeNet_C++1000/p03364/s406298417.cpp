#include "bits/stdc++.h"
#define fio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define endl '\n'
#define all(V) (V).begin(), (V).end() 
using namespace std;
typedef long long ll;
ll mod = 1e9 + 7;
ll B = 101;
ll power(ll base, ll exponent, ll modx = mod) {
    ll ret = 1 % modx; 
    base %= modx; 
    while(exponent) {
        if(exponent & 1) {
            ret = (ret * base) % modx;
        }
        base = (base * base) % modx;
        exponent >>= 1;
    }
    return ret;
}
ll inv(ll val, ll modx = mod) {
    return power(val, modx - 2, modx);
}
int main() {fio;
	int N;
	cin >> N;
	vector <vector <ll>> A(2 * N, vector <ll> (2 * N));
	for(int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for(int j = 0; j < N; j++) {
			A[i][j] = s[j];
			A[i + N][j] = s[j];
			A[i][j + N] = s[j];
			A[i + N][j + N] = s[j];
		}
	}
	vector <vector <ll>> vertical(2 * N, vector <ll> (2 * N)), horizontal(2 * N, vector <ll> (2 * N));
	for(int i = 0; i < 2 * N; i++) {
		for(int j = 0; j < 2 * N; j++) {
			if(i == 0) {
				vertical[i][j] = A[i][j];
			} else {
				vertical[i][j] = (vertical[i - 1][j] * B + A[i][j]) % mod;
			}
			if(j == 0) {
				horizontal[i][j] = A[i][j];
			} else {
				horizontal[i][j] = (horizontal[i][j - 1] * B + A[i][j]) % mod;
			}
			if(i >= N) {
				vertical[i][j] = (vertical[i][j] - (A[i - N][j] * power(B, N)) % mod + mod) % mod;
				vertical[i][j] %= mod;
			}
			if(j >= N) {
				horizontal[i][j] = (horizontal[i][j] - (A[i][j - N] * power(B, N)) % mod + mod) % mod;
				horizontal[i][j] %= mod;
			}
		}
	}
	int ans = 0;
	// h[0][n]
	for(int i = N - 1; i < 2 * N - 1; i++) {
		for(int j = N - 1; j < 2 * N - 1; j++) {
			bool f = 1;
			for(int k = 0; k < N - 1; k++) {
				f &= horizontal[i - k][j] == vertical[i][j - k];
			}
			ans += f;
		}
	}
	cout << ans << endl;
    return 0;
}