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
const int INF = (ll)2e9+7;
const ll INFLL = (ll)1e18;
using namespace std;
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

int main(){
	string str;
	cin >> str;
	int x, y;
	cin >> x >> y;
	vector<int> mx, my;
	mx.push_back(0);
	my.push_back(0);
	int tcount = 0;
	int fcount = 0;
	bool ver = false;
	bool started = true;
	foreach(i, str){
		if(started){
			if(i=='F'){
				--x;
				continue;
			}else{
				started = false;
			}
		}
		if(i=='T'){
			if(ver){
				mx.push_back(0);
				if(my.size()&&my.back()==0)my.pop_back();
			}else{
				my.push_back(0);
				if(mx.size()&&mx.back()==0)mx.pop_back();
			}
			ver = !ver;
		}else{
			if(ver)++my.back();
			else ++mx.back();
		}
	}
	bitset<24001> bs;
	bs.flip(16000);
	foreach(i, mx){
		bs = (bs << i) | (bs >> i);
	}
	if(!bs[x+16000]){
		cout << "No" << endl;
		return 0;
	}
	bs.reset();
	bs.flip(16000);
	foreach(i, my){
		bs = (bs << i) | (bs >> i);
	}
	if(!bs[y+16000]){
		cout << "No" << endl;
		return 0;
	}

	cout << "Yes" << endl;
	return 0;
}
