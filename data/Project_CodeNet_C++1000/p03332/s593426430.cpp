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
const int MOD = 998244353;
const long double PI = (acos(-1));
const long double EPS = 0.0000000001;
int dy[4] = {-2, -1};
int dx[4] = {-1, -2};

int x, y;

const int MAX = 300050;
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

int main(void) {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	//freopen("in.txt", "r", stdin);
	COMinit();
	ll n, a, b, k, x, y;
	cin >> n >> a >> b >> k;
	x = 0;
	ll ret = 0;
	while(k - a * x >= 0) {
		ll z = k - a * x;
		if(z % b == 0) {
			y = z / b;
			ret += COM(n, x) * COM(n, y);
			ret %= MOD;
		}
		x++;
	}
	cout << ret << endl;
	return 0;
}
