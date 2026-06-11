#include "bits/stdc++.h"
using namespace std;
using lint = long long int;
using pint = pair<int, int>;
using plint = pair<lint, lint>;
#define ALL(x) (x).begin(), (x).end()
#define SZ(x) ((lint)(x).size())
#define POW2(n) (1LL << (n))
#define FOR(i, begin, end) for(lint i=(begin),i##_end_=(end);i<i##_end_;i++)
#define IFOR(i, begin, end) for(lint i=(end)-1,i##_begin_=(begin);i>=i##_begin_;i--)
#define REP(i, n) FOR(i,0,n)
#define IREP(i, n) IFOR(i,0,n)
template<class T>bool chmax(T & a, const T & b) { if (a < b) { a = b; return 1; } return 0; }
template<class T>bool chmin(T & a, const T & b) { if (b < a) { a = b; return 1; } return 0; }
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }
const lint MOD = 1e9 + 7, MAX = LLONG_MAX;
typedef pair<string, lint> pa;

unordered_multimap<string, pa> lft, rgh;
int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	string s, l, r;
	lint N;
	cin >> N;
	cin >> s;
	l = s.substr(0, N);
	r = s.substr(N, N);
	reverse(r.begin(), r.end());
	REP(i, 1 << N) {
		string red = "", blue = "";
		REP(j, N) {
			if ((i >> j) % 2 == 1) {
				red += l[j];
			}
			else {
				blue += l[j];
			}
		}
		bool flag = true;
		auto range = lft.equal_range(red);
		for (auto i = range.first; i != range.second; i++) {
			if ((*i).second.first == blue) {
				(*i).second.second++;
				flag = false;
			}
		}
		if(flag) lft.emplace(pair<string, pa>(red, pa(blue, 1)));

		red = "", blue = "";
		REP(j, N) {
			if ((i >> j) % 2 == 1) {
				red += r[j];
			}
			else {
				blue += r[j];
			}
		}
		flag = true;
		range = rgh.equal_range(red);
		for (auto i = range.first; i != range.second; i++) {
			if ((*i).second.first == blue) {
				(*i).second.second++;
				flag = false;
			}
		}
		if (flag) rgh.emplace(pair<string, pa>(red, pa(blue, 1)));
	}

	lint cnt = 0;
	for (auto itr : lft) {
		string key = itr.first, value = itr.second.first;
		auto range = rgh.equal_range(value);
		for (auto i = range.first; i != range.second; i++) {
			if ((*i).second.first == key) {
				cnt += itr.second.second * (*i).second.second;
			}
		}
	}
	cout << cnt << endl;
}
