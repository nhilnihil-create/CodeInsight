#include<bits/stdc++.h>
#define ll long long
#define rep(i, n) for(int i=0;i<(n);++i)
#define per(i, n) for(int i=(n)-1;i>=0;--i)
#define repa(i, n) for(int i=1;i<(n);++i)
#define foreach(i, n) for(auto &i:(n))
#define pii pair<int, int>
#define pll pair<long long, long long>
#define plll pair<ll, pll>
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

using pss = pair<string, string>;

int main(){
	int n;
	cin >> n;
	string str;
	cin >> str;
	map<pss, int> left;
	rep(i, bit(n)){
		string r;
		string b;
		rep(j, n){
			if(bit(j)&i)r+=str[j];
			else b+=str[j];
		}
		++left[pss(r, b)];
	}
	ll ans = 0;
	rep(i, bit(n)){
		string r;
		string b;
		rep(j, n){
			if(bit(j)&i)r+=str[j+n];
			else b+=str[j+n];
		}
		reverse(all(r));
		reverse(all(b));
		pss d(b, r);
		if(left.count(d))ans += left[d];
	}
	cout << ans << endl;
	return 0;
}

