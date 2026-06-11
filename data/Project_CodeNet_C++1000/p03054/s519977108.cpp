#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
template<class T> using V = vector<T>;
template<class T> using VV = V<V<T>>;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

#ifdef LOCAL
#define dump(x) cerr << __LINE__ << " " << #x << " = " << (x) << endl
#else 
#define dump(x) true
#endif

constexpr ll TEN(int n) { return (n == 0) ? 1 : 10 * TEN(n-1); }

template<class T, class U> void chmin(T& t, const U& u) { if (t > u) t = u; }
template<class T, class U> void chmax(T& t, const U& u) { if (t < u) t = u; }

template<class T, class U>
ostream& operator<<(ostream& os, const pair<T, U>& p) {
	os<<"("<<p.first<<","<<p.second<<")";
	return os;
}

template<class T>
ostream& operator<<(ostream& os, const vector<T>& v) {
	os<<"{";
	rep(i, v.size()) {
		if (i) os<<",";
		os<<v[i];
	}
	os<<"}";
	return os;
}

int main() {
	int H, W, N; cin >> H >> W >> N;
	int sr, sc; cin >> sr >> sc; --sr; --sc;
	string S, T;
	cin >> S >> T;

	int minr = 0, maxr = H-1, minc = 0, maxc = W-1;

	dump(mp(mp(minr, maxr), mp(minc, maxc)));

	for (int i = N - 1; i >= 0; --i) {
		if (T[i] == 'L') {
			++maxc;
		} else if (T[i] == 'R') {
			--minc;
		} else if (T[i] == 'U') {
			++maxr;
		} else if (T[i] == 'D') {
			--minr;
		}


		chmax(minr, 0);
		chmin(maxr, H-1);
		chmax(minc, 0);
		chmin(maxc, W-1);

		if (minc > maxc || minr > maxr) {
			puts("NO");
			return 0;
		}

		dump(mp(mp(minr, maxr), mp(minc, maxc)));

		if (S[i] == 'L') {
			++minc;
		} else if (S[i] == 'R') {
			--maxc;
		} else if (S[i] == 'U') {
			++minr;
		} else if (S[i] == 'D') {
			--maxr;
		}

		chmax(minr, 0);
		chmin(maxr, H-1);
		chmax(minc, 0);
		chmin(maxc, W-1);	

		if (minc > maxc || minr > maxr) {
			puts("NO");
			return 0;
		}

		dump(mp(mp(minr, maxr), mp(minc, maxc)));	
	}

	if (minr <= sr && sr <= maxr && minc <= sc && sc <= maxc) {
		puts("YES");
	} else {
		puts("NO");
	}

	return 0;
}