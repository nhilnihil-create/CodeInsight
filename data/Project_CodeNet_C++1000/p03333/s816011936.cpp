#include<bits/stdc++.h>

using namespace std;
typedef long long LL;

#ifdef BTK
#define DEBUG if(1)
#else
#define CIN_ONLY if(1)
struct cww {cww() {CIN_ONLY{ios::sync_with_stdio(false); cin.tie(0);}}
}star;
#define DEBUG if(0)
#endif

#define ALL(v) (v).begin(),(v).end()
#define REC(ret, ...) std::function<ret (__VA_ARGS__)>
template <typename T>inline bool chmin(T &l, T r){bool a = l>r; if (a)l = r; return a;}
template <typename T>inline bool chmax(T &l, T r){bool a = l<r; if (a)l = r; return a;}
template <typename T>istream& operator>>(istream &is, vector<T> &v){for (auto &it : v)is >> it;return is;}

class range {private: struct I { int x; int operator*() { return x; }bool operator!=(I& lhs) { return x<lhs.x; }void operator++() { ++x; } }; I i, n;public:range(int n) :i({ 0 }), n({ n }) {}range(int i, int n) :i({ i }), n({ n }) {}I& begin() { return i; }I& end() { return n; }};

int main() {
	int N;
	cin >> N;
	vector<LL> L(N), R(N);
	for (int i : range(N)) {
		cin >> L[i] >> R[i];
		L[i] *= 2;
		R[i] *= -2;
	}
	sort(ALL(L));
	sort(ALL(R));
	reverse(ALL(L));
	reverse(ALL(R));

	LL ret = 0;
	LL ans = 0;
	for (int i : range(N)) {
		chmax(ret, ans + L[i]);
		chmax(ret, ans + R[i]);
		chmax(ret, ans + R[i] + L[i]);
		ans += L[i] + R[i];
	}
	cout << ret << endl;


	return 0;
}
