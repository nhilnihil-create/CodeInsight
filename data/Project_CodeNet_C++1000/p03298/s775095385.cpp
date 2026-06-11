#include <bits/stdc++.h>

using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> P;

#define REP(i, n) for (int (i) = 0 ; (i) < (int)(n) ; ++(i))
#define REPN(i, m, n) for (int (i) = m ; (i) < (int)(n) ; ++(i))
#define REP_REV(i, n) for (int (i) = (int)(n) - 1 ; (i) >= 0 ; --(i))
#define REPN_REV(i, m, n) for (int (i) = (int)(n) - 1 ; (i) >= m ; --(i))
#define ALL(x) x.begin(), x.end()

#define INF (1e10)
#define MOD (1000000007)

#define print2D(h, w, arr) REP(i, h) { REP(j, w) cout << arr[i][j] << " "; cout << endl; }
template<class T> void print(const T& x){cout << setprecision(12) << x << endl;}
template<class T, class... A> void print(const T& first, const A&... rest) { cout << first << " "; print(rest...); }
struct PreMain {PreMain(){cin.tie(0);ios::sync_with_stdio(false);}} premain;

#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MAX(a,b) ((a) > (b) ? (a) : (b))

#define S_MAX	(5*100100)

void makeM(int N, const string &t, unordered_map<string, int> &m) {
	REP(i, 1<<N) {
		string a, b;
		REP(j, N) {
			if (0 < (i & (1 << j))) {
				a += t[j];
			} else {
				b += t[j];
			}
		}
		m[a + "." + b] += 1;
	}
}

int main() {
	int N;
	string S;

	cin >> N;
	cin >> S;

	string T1 = S.substr(0,N);
	string T2 = S.substr(N);
	reverse(T2.begin(), T2.end());

	unordered_map<string, int> M1, M2;
	makeM(N, T1, M1);
	makeM(N, T2, M2);

	ll cnt = 0;
	for (auto &m : M1) {
		if (M2.count(m.first)) {
			cnt += (ll)m.second * M2[m.first];
		}
	}
	
	print(cnt);
	return 0;
}
