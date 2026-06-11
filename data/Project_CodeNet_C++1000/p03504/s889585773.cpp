#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<cstdlib>
#include<cmath>
#include<numeric>
#include<iomanip>
using namespace std;
using ll =long long;
const int MOD = 1000000007;

//////検証する数,超えられない数////
/*
long long cine(long long a, long long b) {
	if (a <= b) {
		return a;
	}
	else {
		return b;
	}
};*/
//vector型の初期化
/*
void vec_initialize(vector<ll>& a, const ll N) {
	ll c;

	for (int i = 0; i < N; i++) {

		cin >> c;
		a.push_back(c);

	}

};
void vec_pair_initialize(vector<pair<ll, ll>>& a, const ll N) {
	ll c, d;
	for (int i = 0; i < N; i++) {
		cin >> c >> d;
		a.push_back(make_pair(c, d));
	}
};
*/
int main() {
	ll N, C;
	vector<ll>s, t, c;
	cin >> N >> C;
	ll x,y,z;
	map<ll, ll>chanel;
	for (ll i = 0; i < N; i++) {
		cin >> x>>y>>z;
		s.push_back(2*x-1);
		t.push_back(2*y);
		c.push_back(z);
	}
	
	map<ll,ll>tmpc;
	
	for (ll i = 1; i <=C; i++) {
		vector<ll> tmps;
		vector<ll> tmpt;
		
		for (ll j = 0; j < N; j++) {
			if (c[j] == i) {
				tmps.push_back(s[j]);
				tmpt.push_back(t[j]);
				
				tmpc[i-1]++;
			}
		}
		sort(tmps.begin(), tmps.end());
		sort(tmpt.begin(), tmpt.end());
		for (ll j = 0; j < tmpc[i - 1]; j++) {
			if (j+1!=tmpc[i-1]&&tmps[j+1] < tmpt[j]) {
				tmps[j + 1] += 2;
			}
		}
		for (ll j = 0; j < tmpc[i - 1]; j++) {
			for (ll k = tmps[j]; k <= tmpt[j]; k++) {

				chanel[k]++;

			}
		}


	}
	ll big=0;
	for (auto i : chanel) {
		if (i.second > big) {

			big = i.second;
		}

	}

	cout <<big;


}