#pragma GCC optimize("Ofast")

#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define all(x) x.begin(), x.end()
#define mp make_pair

typedef long long ll;
typedef unsigned long long int ull;
typedef long double ld;

typedef pair<int, int> pii;
typedef pair<ll, int> pli;

typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<int> vi;

typedef map<string, int> msi;
typedef map<int, int> mii;
typedef map<int, ll> mill;
typedef map<int, vi> mivi;

const int MAXN = 17;
const int MAXS = 160;

int memo[MAXN][MAXS][2];
vi dig;

ll n;
int N;

void fast_io() {
	ios::sync_with_stdio(false);
	cin.tie(NULL);
}

void prepare() {
	memset(memo, -1, sizeof(memo));
	while(n) {
		dig.pb(n % 10);
		n /= 10;
	}
	N = dig.size();
	reverse(all(dig));
}

int solve(int pos, int sum, bool tight) {
	if(pos == N) 
		return sum;
	
	if(memo[pos][sum][tight] != -1)
		return memo[pos][sum][tight];
	
	int lim = (tight ? dig[pos] : 9);
	int res = 0;
	
	for(int i = 0; i <= lim; i++) {
		bool nt = (i == lim) ? tight : 0;
		res = max(res, solve(pos + 1, sum + i, nt));
	}
	
	return memo[pos][sum][tight] = res;
}

int main() {
	fast_io();
//	freopen("input/agc021a.txt", "r", stdin);
	
	cin >> n;
	prepare();
	cout << solve(0, 0, 1) << '\n';
}