#include "bits/stdc++.h"
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long

int N;
int F[210010];
int Finv[210010];

int Mul(int a, int b) {
	return ((a % mod) * (b % mod)) % mod;
}

int square(int x) {
	return (x * x) % mod;
}

int power(int x, int y) {
	if (y == 0) return 1;
	else if (y == 1) return x % mod;
	else if (y % 2 == 0) return square(power(x, y / 2)) % mod;
	else return square(power(x, y / 2)) * x % mod;
}

int Div(int a, int b) {
	return Mul(a, power(b, mod - 2)) % mod;
}

void fact(void) {
	F[0] = 1;
    Finv[0] = 1;
	for (int i = 1; i <= 210000; i++) {
		F[i] = Mul(i, F[i - 1]);
        Finv[i] = power(i, mod - 2);
	}
}

signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> N;
    fact();
    //rep(i, N) cout << i << " " << F[i] << " " << Finv[i] << endl;
    REP(i, 2, N) Finv[i] = (Finv[i] + Finv[i - 1]) % mod;
    int ans = 0;
    int A[200010];
    REP(i, 1, N) {
        cin >> A[i];
        ans = (ans + A[i] * (Finv[i] + Finv[N - i + 1] - 1) + mod) % mod;
    }
    cout << ans * F[N] % mod << endl;

    return 0;
}
