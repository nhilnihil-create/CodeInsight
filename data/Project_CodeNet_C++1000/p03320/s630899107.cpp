#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<ll, double> P;
int k;
ll digitsum(ll x){
	ll res = 0;
	while(x > 0){
		res += x % 10;
		x /= 10;
	}
	return res;
}
vector<P> v;
vector<ll> w;
set<ll> st;

int main(){
//	cin.tie(0);
//	ios::sync_with_stdio(false);
	cin >> k;
	for(int i=0; i<16; ++i){
		for(int j=0; j<1000; ++j){
			if(i == 0 && j == 0) continue;
			ll t = j;
			for(int k=0; k<i; ++k)
				t = t * 10 + 9;
			if(st.find(t) != st.end()) continue;
			st.insert(t);
			v.push_back(P(t, (double)t/digitsum(t)));
		}
	}
//	for(int i=0; i<100; ++i) cout << v[i].first << "\n";
//	cout << "hoge\n";
	double m = v[v.size()-1].second;
	for(int i=v.size()-2; i>=0; --i){
		if(v[i].second < m + 1e-14){
			m = v[i].second;
			w.push_back(v[i].first);
		}
	}
	reverse(w.begin(), w.end());
	for(int i=0; i<k; ++i) cout << w[i] << "\n";
}