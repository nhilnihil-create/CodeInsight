#include <bits/stdc++.h>
using namespace std;

#define INF_LL (int64)1e18
#define INF (int32)1e9
#define REP(i, n) for(int64 i = 0;i < (n);i++)
#define FOR(i, a, b) for(int64 i = (a);i < (b);i++)
#define all(x) x.begin(),x.end()
#define fs first
#define sc second

using int32 = int_fast32_t;
using uint32 = uint_fast32_t;
using int64 = int_fast64_t;
using uint64 = uint_fast64_t;
using PII = pair<int32, int32>;
using PLL = pair<int64, int64>;

const double eps = 1e-10;

template<typename A, typename B>inline void chmin(A &a, B b){if(a > b) a = b;}
template<typename A, typename B>inline void chmax(A &a, B b){if(a < b) a = b;}

template<typename T>
vector<T> make_v(size_t a){return vector<T>(a);}

template<typename T,typename... Ts>
auto make_v(size_t a,Ts... ts){
  return vector<decltype(make_v<T>(ts...))>(a,make_v<T>(ts...));
}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value!=0>::type
fill_v(U &u,const V... v){u=U(v...);}

template<typename T,typename U,typename... V>
typename enable_if<is_same<T, U>::value==0>::type
fill_v(U &u,const V... v){
  for(auto &e:u) fill_v<T>(e,v...);
}

char dir[5] = "RUDL";
int64 rid[256]={};
int64 dx[4] = {1, -1, 1, -1};
int64 dy[4] = {1, 1, -1, -1};


vector<int64> calc(int64 x) {
	int64 xx = abs(x);
	int64 sgn = x < 0 ? 1 : 0;
	vector<int64> v;
	int64 bef = 0;
	for (int64 i = 38; i >= 0; i--) {
		if (bef) {
			v.push_back(1-sgn);
		} else {
			v.push_back(sgn);
		}
		if (xx >> i & 1) {
			bef = 0;
		} else {
			bef = 1;
		}
	}
	return v;
}

PLL topoint(const vector<int64>& d, string& s) {
	PLL p(0, 0);
	REP(i, s.size()) {
		if (s[i] == 'L') p.fs -= d[i];
		if (s[i] == 'R') p.fs += d[i];
		if (s[i] == 'U') p.sc += d[i];
		if (s[i] == 'D') p.sc -= d[i];
	}
	return p;
}

int main(void) {
	int64 N;
	cin >> N;
	vector<int64> X(N), Y(N);
	vector<int64> U(N), V(N);
	int64 parity = -1;
	REP(i, N) {
		cin >> X[i] >> Y[i];
		if (parity != -1 && parity != abs(X[i]+Y[i])%2) {
			cout << -1 << endl;
			return 0;
		} else {
			parity = abs(X[i]+Y[i])%2;
		}
		U[i] = X[i]-Y[i]; V[i] = X[i]+Y[i];
	}
	vector<int64> d(39, 0);
	string res = "";
	REP(i, 39) d[i] = 1LL << i;
	if (parity == 0) {
		d.push_back(1);
		res = "D";
		REP(i, N) {
			U[i] += -1;
			V[i] += 1;
		}
	}
	cout << d.size() << endl;
	REP(i, d.size()) cout << d[i] << " ";
	cout << endl;
	REP(i, N) {
		string ret = res;
		auto du = calc(U[i]);
		auto dv = calc(V[i]);
		REP(j, 39) {
			ret = dir[du[j] | (dv[j] << 1)] + ret;
		}
		// cout << U[i] << " " << V[i] << endl;
		// for (int64 j = 32; j >= 0; j--) {
		// 	cout << "(" << du[j] << " " << dv[j] << ") ";
		// }
		// cout << endl;
		// if (PLL(x, y) != topoint(d, ret)) {
		// 	cout << x << " " << y << endl;
		// }
		cout << ret << endl;
	}
}