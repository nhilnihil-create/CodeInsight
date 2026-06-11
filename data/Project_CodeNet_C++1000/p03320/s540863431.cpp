//#include "stdafx.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <queue>
#include <vector>
#include <cassert>
#include <fstream>
#include <algorithm>
#include <list>
#include <random>
#include <ctime>
#include <cmath>
#include <random>
#include <bitset>
#include <complex>

using namespace std;

typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
//#define int ll
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<int> vi;
typedef vector< vi > vvi;
typedef vector< vvi > vvvi;
typedef vector<short> vs;
typedef vector<vs> vvs;
typedef vector<vvs> vvvs;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vvl> vvvl;
typedef pair<ld, ld> pld;
typedef complex<double> base;

#define mmin(a, b) a = min(a, (b))
#define mmax(a, b) a = max(a, (b))
#define mp(a,b) make_pair(a,b)
#define pb(a) push_back(a)
#define ALL(a) a.begin(),a.end()
#define sqr(x) (x) * (x)
#define fori(i, n) for(int i = 0; i < int(n); ++i)
#define cint const int & 
#define SZ(a) ((int)(a.size()))
#define watch(x) cout << (#x) << " = " << x << endl;

const double PI = 2 * acos(0.0);

template<class T>
void show(const vector<T> &a) {
	for (T x : a)
		cout << x << " ";
	cout << endl;
}

ll gets(ll n) {
	ll ret = 0;
	while (n) {
		ret += n % 10;
		n /= 10;
	}
	return ret;
}

vl good() {
	vl pred;
	for (int sm = 1; sm < 200; ++sm) {
		string s = "";
		int kek = sm;
		for (int i = 9; i >= 1; --i) {
			while (kek >= i) {
				s = char(i + '0') + s;
				kek -= i;
			}
		}
		stringstream ss;
		ss << s;
		ll lol;
		ss >> lol;
		pred.pb(lol);
		int lst = s[0] - '0';
		string ns = s.substr(1, SZ(s) - 1);
		for (int i = 0; i < lst; ++i) {
			string kek_ns = ns;
			kek_ns = char(i + '0') + kek_ns;
			kek_ns = char((lst - i) + '0') + kek_ns;
			ll lol;
			stringstream ss;
			ss << kek_ns;
			ss >> lol;
			pred.pb(lol);
		}
	}
	vl ret;
	sort(ALL(pred));
	pred.resize(unique(ALL(pred)) - pred.begin());
	//watch(SZ(pred));
	for (int i = 0; i < SZ(pred); ++i) {
		bool ok = 1;
		for (int j = i + 1; ok && j < SZ(pred); ++j) {
			ld a = (ld)pred[i] * (ld)gets(pred[j]);
			ld b = (ld)pred[j] * (ld)gets(pred[i]);
			if (a > b) ok = 0;
		}
		if (ok) ret.pb(pred[i]);
	}
	//watch(SZ(ret));
	return ret;
}

bool check(ll n, vl ret) {
	for (int j = 0; j < SZ(ret); ++j) {
		ld a = (ld) n * (ld) gets(ret[j]);
		ld b = (ld) ret[j] * (ld) gets(n);
		if (n < ret[j] && a > b) 
			return 0;
		
	}
	return 1;
}

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int k;
	cin >> k;
	vl ret = good();
	vl addition;
	string nines = "";
	for (int i = 1; i < 15; ++i, nines += '9') {
		for (int j = 1; ; ++j) {
			stringstream ss;
			ss << j;
			ss << nines;
			ll kek;
			ss >> kek;
			if (check(kek, ret)) addition.pb(kek);
			else break;
		}
	}
	//watch(SZ(addition));
	ret.insert(ret.end(), ALL(addition));
	sort(ALL(ret));
	ret.resize(unique(ALL(ret)) - ret.begin());
	fori(i, k)
		cout << ret[i] << " ";
}
