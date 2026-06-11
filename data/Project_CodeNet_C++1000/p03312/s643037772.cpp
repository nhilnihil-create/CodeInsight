#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i=0;i<(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define repa(i, n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define all(x) (x).begin(), (x).end()
#define bit(x) (1ll << (x))
const ll MOD = (ll)1e9+7;
const int INF = (ll)1e9+7;
const ll INFLL = (ll)1e18;
using namespace std;
template<class t>
using vvector = vector<vector<t>>;
template<class t>
using vvvector = vector<vector<vector<t>>>;
template<class t>
using priority_queuer = priority_queue<t, vector<t>, greater<t>>;
template<class t, class u> bool chmax(t &a, u b){if(a<b){a=b;return true;}return false;}
template<class t, class u> bool chmin(t &a, u b){if(a>b){a=b;return true;}return false;}

ll modpow(ll x, ll b){
	ll res = 1;
	while(b){
		if(b&1)res = res * x % MOD;
		x = x * x % MOD;
		b>>=1;
	}
	return res;
}

ll modinv(ll x){
	return modpow(x, MOD-2);
}

bool was_output = false;
template<class t>
void output(t x){
	if(was_output)cout << " ";
	was_output = true;
	cout << x;
}

void outendl(){
	was_output = false;
	cout << endl;
}

int main(){
	int n;
	cin>>n;
	vector<ll> line(n);
	foreach(i, line)cin>>i;
	vector<ll> sum(n+1, 0);
	rep(i, n)sum[i+1]=sum[i]+line[i];
	ll ans = INFLL;
	for(int i=2;i<n-1;++i){
		vector<pll> left, right;
		ll l = sum[i];
		ll r = sum[n]-l;
		int p = lower_bound(all(sum), l/2) - sum.begin();
		ll a = sum[p];
		ll b = sum[i]-sum[p];
		if(a>b)swap(a, b);
		left.push_back(pll(a, b));
		a = sum[p-1];
		b = sum[i] - sum[p-1];
		if(a>b)swap(a, b);
		left.push_back(pll(a, b));
		p = lower_bound(all(sum), l+r/2)-sum.begin();

		a = sum[p] - sum[i];
		b = sum[n] - sum[p];
		if(a>b)swap(a, b);
		right.push_back(pll(a, b));
		a = sum[p-1] - sum[i];
		b = sum[n] - sum[p-1];
		if(a>b)swap(a, b);
		right.push_back(pll(a, b));
		foreach(j, left){
			foreach(k, right){
				ll nmin = min(j.first, k.first);
				ll nmax = max(j.second, k.second);
				chmin(ans, nmax-nmin);
			}
		}
	}

	cout << ans << endl;
	return 0;
}


