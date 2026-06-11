#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second
const int INF = 1000000007;
const int MOD = (int)1e9+7;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;
int dy[4] = {-2, -1};
int dx[4] = {-1, -2};

const int MAX = 1000050;
long long fac[MAX], finv[MAX], inv[MAX];
 
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}

long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}

// 
const int MAX_N = 10050;
int n, m;
int cost[10] = {0, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int a[10];
string dp[MAX_N];

void chmax(string& a, string b) {
	if(a.size() < b.size()) {
		a = b;
		return;
	} else if (a.size() > b.size()) {
		return;
	}

	rep(i,0,sz(a)) {
		if(a[i] < b[i]) {
			a = b;
			return;
		} else if (a[i] > b[i]) {
			return;
		}
	}
}

int main(void) {
	ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n >> m;
	rep(i,0,m) {
		cin >> a[i];
	}

	rep(i,0,MAX_N) {
		dp[i] = "";	
	}
	dp[0] = "0";

	for(int i = 0; i <= n; ++i) {
		if(dp[i] == "") continue;
		for(int j = 0; j < m; ++j) {
			int idx = i+cost[a[j]];
			if(idx > n) continue;
			string num = dp[i] + string(1,(char)(a[j]+'0'));
			chmax(dp[idx], num);
		}
	}
	//rep(i,0,n+1) {
	//	cout << i << " : " << dp[i] << endl;
	//}
	cout << dp[n].substr(1) << endl;
	return 0;
}
