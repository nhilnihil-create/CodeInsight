#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const ll MOD = 1000000007;
const int MN = 100010;

int N;
int A[MN];
ll ret;
ll inv[MN];
ll ac[MN];

int main() {
	inv[1] = 1;
    for (int i = 2; i < MN; ++i) {
        inv[i] = inv[MOD % i] * (MOD - MOD / i) % MOD;
    }

    for (int i = 1; i < MN; ++i) {
    	ac[i] = (ac[i-1] + inv[i]) % MOD;
    }

	cin >> N;
	rep(i, N) cin >> A[i];

	rep(i, N) {
		int l = i;
		int r = N - 1 - i;
		ll t = (ac[l+1] - 1 + ac[r+1]) * A[i] % MOD;
		ret = (ret + t) % MOD;
	}

	for (int i = 1; i <= N; ++i) {
		ret = ret * i % MOD;
	}

	cout << ret << endl;
	return 0;
}