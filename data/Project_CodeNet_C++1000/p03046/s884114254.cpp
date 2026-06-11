#define rep(i, n) for(int i=0; i<(n); ++i)
#define rrep(i, n) for(int i=(n-1); i>=0; --i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()
#define memr(dp, val) memset(dp, val, sizeof(dp))
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
template<class T> inline T int_ceil(T a, T b) { T res = a / b; if(a % b != 0) res++; return res; }
#include <bits/stdc++.h>
using namespace std;
template<typename T>
using min_priority_queue = priority_queue<T, vector<T>, greater<T> >;
typedef long long ll;
static const int INTINF = (INT_MAX >> 1); // 10^9 + 10^7
static const ll LLINF = (LLONG_MAX >> 1);
// sort(ALL(v), [](auto const& lhs, auto const& rhs) { return lhs > rhs; /* 左の方が大きい...というイメージ。*/ });
// --------------------------------------------------------------------------------------------- //

static const int MAX = 100001;
static const ll MOD = 1000000007;


int main(int argc, const char * argv[]) {
	std::cout << std::fixed << std::setprecision(15);

	int M, K; cin >> M >> K;
	if(M == 0 && K == 0){
		cout << 0 << " " << 0 << endl;
		return 0;
	}
	if(M == 1 && K == 1){
		cout << -1 << endl;
		return 0;
	}
	int lim = 2 << (M-1);
	vector<int> v;
	if(K == 0){
		rep(i, lim){
			if(i) cout << " ";
			rep(_, 2){
				if(_) cout << " ";
				cout << i;
			}
		}
		cout << endl;
		return 0;
	}
	if(K >= lim){
		cout << -1 << endl;
		return 0;
	}
	else{
		rep(i, lim){
			if(i == K) continue;
			v.push_back(i);
		}
		v.push_back(K);
		rrep(i, lim){
			if(i == K) continue;
			v.push_back(i);
		}
		v.push_back(K);
	}
	rep(i, v.size()){
		if(i) cout << " ";
		cout << v[i];
	}
	cout << endl;

	return 0;
}
