#include <bits/stdc++.h>

using namespace std;

#define f first
#define s second
#define pb push_back
#define mp make_pair
#define all(v) v.begin(), v.end()
#define sz(v) (int)v.size()

#define MOO(i, a, b) for (int i=a; i<b; i++)
#define M00(i, a) for (int i=0; i<a; i++)
#define MOOd(i,a,b) for (int i = (b)-1; i >= a; i--)
#define M00d(i,a) for (int i = (a)-1; i >= 0; i--)

#define FAST ios::sync_with_stdio(0); cin.tie(0);
#define finish(x) return cout << x << '\n', 0;
#define dbg(x) cerr << ">>> " << #x << " = " << x << "\n";
#define _<< " _ " <<

typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ld,ld> pd;
typedef vector<ll,ll> vll;
typedef pair<ll,ll> pll;

//DP[i][j] = placed i pieces,  of n-i left, (0 to j) are greater than last placed
ll DP[3010][3010];
ll MOD = 1e9+7;

int main() { FAST
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	int n; string s;
	cin >> n >> s;
	
	DP[n][0] = 1;

	for(int i = n-1; i > 0; i--) {
		for(int j = 0; j <= n - i; j++) {
			if(j == 0) DP[i][j] = 0;
			else DP[i][j] = DP[i][j-1];

			if(s[i-1] == '<') {
				if(j != 0) DP[i][j] += DP[i+1][j-1];
			} else {
				DP[i][j] += DP[i+1][n-i-1];
				if(j != 0) DP[i][j] -= DP[i+1][j-1];
			}
			DP[i][j] += MOD;
			DP[i][j] %= MOD;

		}
	}
	finish(DP[1][n-1] % MOD);
}
