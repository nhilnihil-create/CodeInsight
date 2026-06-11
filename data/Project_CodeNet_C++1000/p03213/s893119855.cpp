
#include<bits/stdc++.h>
using namespace std;

#define fastio 			ios::sync_with_stdio(0);	cin.tie(0); cout.tie(0);  cout<<fixed;  cout<<setprecision(12);
#define randomINT 		mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());
#define	newl 			cout<<"\n"
#define DISP(as)		for(auto it : as) cout<<it<<" ";newl;
#define DISP1(as)		for(auto it : as) cout<<it.f<<" "<<it.s<<") ";newl;
#define all(x)         	(x).begin(),(x).end()
#define mset(x,val)    	memset(x,val,sizeof(x))
#define newl           	cout<<"\n"
#define pb             	push_back
#define mp             	make_pair
#define f 				first
#define s 				second
#define dline          cerr<<"///REACHED///\n";
#define deb1(x)        cerr<<#x<<" = "<<x<<'\n';
#define deb2(x,y)      cerr<<'['<<#x<<','<<#y<<"] = "<<'['<<x<<','<<y<<']'<<'\n';
#define deb3(x,y,z)    cerr<<'['<<#x<<','<<#y<<','<<#z<<"] = "<<'['<<x<<','<<y<<','<<z<<']'<<'\n';

typedef long long 				ll;
typedef long double 			ld;
typedef vector<ll> 				vll;
typedef pair<ll , ll> 			pll;
typedef pair<ld, ld> 			pld;
typedef unordered_map<ll, ll> 	um;
typedef vector<pll> 			vpll;

const ll 	MAX5 	= 	2e+5 + 99;
const ll 	MAX7 	= 	1e+7 + 7;
const ll 	MAXN 	= 	MAX7;
const ll   	INF   	=  	0x7f7f7f7f7f7f7f7f;
const int  	INFi 	=  	0x7f7f7f7f;
const ll 	MOD		=  	1e+9 + 7;

// <------------- Declare Variables Here ------------> //

ll T = 1;
ll n, k, l, q, x;
string s;
ll prime[200];
// < ----------- func eh ---------------- ? //

void PRIME() {
	for (ll i = 0; i <= 100; i++) {
		prime[i] = i;
	}

	for (ll i = 4; i <= 100; i += 2) {
		prime[i] = 2;
	}

	for (ll i = 3; i <= 100; i += 2) {
		if (prime[i] == i) {
			for (ll j = i * i; j <= 100; j += i) {
				if (prime[j] == j) prime[j] = i;
			}
		}
	}
}

map<ll , ll> factorize(ll x) {
	map<ll, ll> ans;

	while (x > 1) {
		ll m = prime[x];
		while (x % m == 0) {
			ans[m] = (ans[m] + 1) % MOD;
			x /= m;
		}
	}
	return ans;
}

// <------------- Start of main() -------------------> //

void MAIN() {
	cin >> n;
	map<ll, ll> ans, ans1;
	for (ll i = 2; i <= n; i++) {
		ans1 = factorize(i);
		for (auto it : ans1) {
			ans[it.f] += it.s;
		}
	}
	
	vll cnt(100, 0);
	for (auto it : ans) {
		//cout<<it.f<<" "<<it.s;newl;
		cnt[it.s + 1] += 1	;
	}

	for(ll i=99;i>=0;i--) cnt[i]+=cnt[i+1];
	//DISP(cnt);
	//dline;
	ll Ans = 0;
	Ans = cnt[75] + (cnt[25] * (cnt[3] - 1)) + (cnt[15] * (cnt[5] - 1))  +  (cnt[5] * (cnt[5]-1) * (cnt[3]-2))/2;
	cout << Ans;
}

int main() {
	fastio; randomINT;
	//cin >> T;
	PRIME();
	while (T--) {
		MAIN();
	}
	return 0;
}
