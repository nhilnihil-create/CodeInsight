#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

using ll = long long;

#define FOR(i, a, b) for(int i=(a);i<(b);++i)
#define REP(i, n) for(int i=0;i<(n);++i)
#define ALL(v) (v).begin(),(v).end()

typedef pair<int, int> P;

const int MOD = (int) 1e9 + 7;

template<class T>
bool chmax(T &a, const T &b) {
	if (a < b) {
		a = b;
		return 1;
	}
	return 0;
}

template<class T>
bool chmin(T &a, const T &b) {
	if (b < a) {
		a = b;
		return 1;
	}
	return 0;
}

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

int n;
int a[200005], b[200005];

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	REP(i, n) cin >> a[i];
	REP(i, n) cin >> b[i];
	
	int ans = 0;
	REP(i, 30) {
		vector<int> v;
		REP(j, n) v.push_back(b[j] % (1 << (i + 1)));
		REP(j, n) v.push_back((1 << (i + 1)) + b[j] % (1 << (i + 1)));
		sort(ALL(v));
		
		int cnt = 0;
		REP(j, n) {
			int low1 = lower_bound(ALL(v), (4 << i) - a[j] % (1 << (i + 1))) - v.begin();
			int low2 = lower_bound(ALL(v), (3 << i) - a[j] % (1 << (i + 1))) - v.begin();
			cnt += low1 - low2;
			cnt %= 2;
		}
		ans += cnt << i;
	}
	
	cout << ans << endl;
	
	return 0;
}