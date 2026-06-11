#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

inline vector<ll> get(vector<ll> &s, ll x){
	vector<ll> ret;
	int ind = lower_bound(s.begin(), s.end(), x) - s.begin();
	if(ind != s.size())ret.push_back(s[ind]);
	if(ind != 0)ret.push_back(s[ind - 1]);
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	int a, b, q;
	cin>>a>>b>>q;
	vector<ll> s(a), t(b);
	for(auto &x : s){
		cin>>x;
	}
	for(auto &x : t){
		cin>>x;
	}
	ll x;
	while(q--){
		cin>>x;
		vector<ll> vs = get(s, x);
		vector<ll> vt = get(t, x);
		ll ans = 1e18;
		for(auto xx : vs){
			for(auto yy : vt){
				ans = min(ans, abs(x - xx) + abs(xx - yy));
			}
		}
		for(auto xx : vt){
			for(auto yy : vs){
				ans = min(ans, abs(x - xx) + abs(xx - yy));
			}
		}
		cout<<ans<<'\n';
	}

	return 0;
}