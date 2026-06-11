/* #include */
#include"bits/stdc++.h"
#include <sstream>
/* 名前空間 */
using namespace std;

/* #define */
// リピート
#define rpt0(i, n) for(ll i = 0; i < (n); i++)  // リピート 0からn - 1まで
#define rpt1(i, n) for(ll i = 1; i <= (n); i++)  // リピート 1からnまで
#define rptb0(i ,n) for(ll i = (n) - 1; i >= 0; --i) // バックするリピート n - 1から0まで
#define rptb1(i ,n) for(ll i = (n); i >= 1; --i) // バックするリピート nから1まで
// 実用省略
#define pb push_back
#define all(v) v.begin(),v.end()
// 数学
#define PI (acos(-1))  // 円周率pi

/* typedef */
// long系
typedef long long ll;
typedef long double ld;
// vector
typedef vector<int> vint; // intのvector
typedef vector<double> vdouble; // doubleのvector
typedef vector<ll> vll; // llのvector
typedef vector<ld> vld; // ldのvector
typedef vector<pair<ll, ll>> vl_l; // l_lのvector
typedef vector<pair<int, int>> vi_i; // i_iのvector
typedef vector<pair<double, double>> vd_d; // d_dのvector
// pair系
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
typedef pair<double, double> d_d;

/* 入出力 read, write */
/* 変数入力 */
// 1変数
template <typename T>
void read(T& x) {
	cin >> x;
}
// 2変数
template <typename T, typename T0>
void read(T& x, T0& y) {
	cin >> x >> y;
}
// 3変数
template <typename T, typename T0, typename T1>
void read(T& x, T0& y, T1& z) {
	cin >> x >> y >> z;
}
// 4変数
template <typename T, typename T0, typename T1, typename T2>
void read(T& x, T0& y, T1& z, T2& w) {
	cin >> x >> y >> z >> w;
}

/* vector, 配列, pair入力 */
// vector
template <typename T>
void read(vector< T >& oneD, int n) {
	ll n1 = (ll)n;
	rpt0(i, n1)
	{
		ll x;
		read(x);
		oneD.push_back(x);
	}
}
template <typename T>
void read(vector< T >& oneD, ll n) {
	rpt0(i, n)
	{
		ll x;
		read(x);
		oneD.push_back(x);
	}
}
// 配列
template <typename T>
void read(T oneD[], int n) {
	ll n1 = (ll)n;
	rpt1(i, n1) {
		read(oneD[i]);
	}
}
template <typename T>
void read(T oneD[], ll n) {
	rpt1(i, n) {
		read(oneD[i]);
	}
}
// pair
template <typename T, typename T0>
void read(pair< T, T0 >& p) {
	cin >> p.first >> p.second;
}

/* 変数出力 */
// 1変数
template <typename T>
void write(T& x) {

	cout << x << endl;
}
// 2変数
template <typename T, typename T0>
void write(T& x, T0& y) {
	cout << x << " " << y << "\n";
}
// 3変数
template <typename T, typename T0, typename T1>
void write(T& x, T0& y, T1& z) {
	cout << x << " " << y << " " << z << "\n";
}
// 4変数
template <typename T, typename T0, typename T1, typename T2>
void write(T& x, T0& y, T1& z, T2& w) {
	cout << x << " " << y << " " << z << " " << w << "\n";
}

/* vector, 配列, pair出力 */
// vector
template <typename T>
void write(vector< T >& oneD, int n) {
	ll n1 = (ll)n;
	rpt0(i, n1) {
		cout << oneD[i] << " ";
	}
	cout << endl;
}
template <typename T>
void write(vector< T >& oneD, ll n) {
	rpt0(i, n) {
		cout << oneD[i] << " ";
	}
	cout << endl;
}
// 配列
template <typename T>
void write(T oneD[], int n) {
	ll n1 = (ll)n;
	rpt1(i, n1) {
		write(oneD[i]);
	}
	cout << endl;
}
template <typename T>
void write(T oneD[], ll n) {
	rpt1(i, n) {
		write(oneD[i]);
	}
	cout << endl;
}
// pair
template <typename T, typename T0>
void write(pair< T, T0 >& p) {
	cout << p.first << " " << p.second << " ";
	cout << endl;
}


bool cmp(i_i a, i_i b) {
	return a.first < b.first;
}


int main(void) {
	int n; read(n);
	vi_i r; r.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> r[i].first >> r[i].second;
	}
	vi_i b; b.resize(n);
	for (int i = 0; i < n; i++) {
		cin >> b[i].first >> b[i].second;
	}
	sort(all(r), cmp); sort(all(b), cmp);
	
	int ans = 0;
	vi_i reg;
	for (int i = 0; i < n; i++) {	// b側インデックス
		reg.clear();
		for (int j = 0; j < n; j++) {	// r側インデックス
			if (r[j].first < b[i].first && r[j].second < b[i].second) {
				reg.push_back(r[j]);
			}
		}
		if (reg.empty() != true) {
			int idx = -1;
			int max = -1;
			for (int k = 0; k < reg.size(); k++) {
				if (max < reg[k].second) {
					idx = k;
					max = reg[k].second;
				}
			}
			if (idx != -1) {
				ans++;
				auto itr = find(all(r), reg[idx]);
				i_i  pmax(10000, 10000);
				*itr = pmax;
			}
		}
	}
	write(ans);

	return 0;
}