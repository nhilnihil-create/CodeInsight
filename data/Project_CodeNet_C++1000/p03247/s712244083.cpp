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

string s[2][2] = { {"R","U"}, {"D","L"} };
LL x[112345];
LL y[112345];
int main() {
	int N;
	cin >> N;
	vector<string> ret(N);
	vector<LL> d;
	for (int i : range(N)) {
		cin >> x[i] >> y[i];
	}
	for (int i : range(N-1)) {
		if (abs(x[i]+y[i]) % 2 != abs(x[i+1]+y[i+1]) % 2) {
			cout << -1 << endl;
			return 0;
		}
	}
	if (abs(x[0] + y[0]) % 2 == 0) {
		d.push_back(1);
	}
	for (int i : range(31))d.push_back(1ll << i);

	for (int i : range(N)) {
		LL nx = x[i] + y[i];
		LL ny = x[i] - y[i];
		if (abs(x[i] + y[i]) % 2 == 0) {
			nx++;
			ny++;
			ret[i] += "L";
		}
		nx = ((1ll << 31) - 1) - nx;
		ny = ((1ll << 31) - 1) - ny;
		nx /= 2;
		ny /= 2;
		for (int j : range(31)) {
			ret[i] += s[nx % 2][ny % 2];
			nx /= 2;
			ny /= 2;
		}
	}
	cout << d.size() << endl;
	string sp(d.size(), ' ');
	sp.back() = '\n';
	for (int i : range(d.size()))cout << d[i] << " " << sp[i];
	for (int i : range(N)) {
		cout << ret[i] << endl;
		DEBUG {
			for (int j : range(d.size())) {
				if (ret[i][j] == 'L')x[i] += d[j];
				if (ret[i][j] == 'R')x[i] -= d[j];
				if (ret[i][j] == 'D')y[i] += d[j];
				if (ret[i][j] == 'U')y[i] -= d[j];
			}
		if (x[i] != 0 || y[i] != 0) {
			cout << "NG" << endl;
		}

		}
	}
	return 0;
}
