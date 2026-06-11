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
template<typename T1, typename T2> pair<T1, T2> operator+(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first + r.first, l.second + r.second); }
template<typename T1, typename T2> pair<T1, T2> operator-(const pair<T1, T2>& l, const pair<T1, T2>& r) { return make_pair(l.first - r.first, l.second - r.second); }

lint N;
lint arr[200000];
lint pos[200000];
int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	REP(i, N) {
		cin >> arr[i];
	}
	REP(i, N) {
		pos[arr[i] - 1] = i;
	}
	lint curr = pos[0], cnt = 1, max_cnt = 0;
	REP(i, N - 1) {
		if (curr < pos[i + 1]) {
			cnt++;
		}
		else {
			max_cnt = max(max_cnt, cnt);
			cnt = 1;
		}
		curr = pos[i + 1];
	}
	max_cnt = max(max_cnt, cnt);
	cout << N - max_cnt;
}
