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
const lint MOD = 1e9 + 7;

lint N, A, B, ind = 0;
lint arr[10000];
lint val[10000];
vector<lint> to[10000];

void dfs(lint curr, lint prev) {
	val[curr] = arr[ind];
	ind++;
	REP(i, to[curr].size()) {
		lint next = to[curr][i];
		if (next == prev) continue;
		dfs(next, curr);
	}
}

int main() {
	cin.tie(0); ios_base::sync_with_stdio(false);
	cin >> N;
	fill((long long*)val, (long long*)val + sizeof(val) / sizeof(long long), 0);
	REP(i, N - 1) {
		cin >> A >> B; A--; B--;
		to[A].push_back(B);
		to[B].push_back(A);
	}
	REP(i, N) {
		cin >> arr[i];
	}
	sort(arr, arr + N, greater<lint>());
	lint sum = 0;
	REP(i, N - 1) {
		sum += arr[i + 1];
	}
	val[0] = arr[ind];
	ind++;
	REP(i, to[0].size()) {
		dfs(to[0][i], 0);
	}
	cout << sum << endl;
	REP(i, N) {
		cout << val[i] << " ";
	}
}
