#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cassert>
#include <climits>
#include <algorithm>
#include <string>
#include <sstream>
#include <complex>
#include <vector>
#include <list>
#include <queue>
#include <deque>
#include <stack>
#include <map>
#include <set>
#include <fstream>

using namespace std;
#define TOSTRING(x) #x
#define SZ(x) (int)(x).size()
#define REP(i,n) for(int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define REPR(i,n) for(int i=(n)-1;i>=0;i--)
#define ALL(s) (s).begin(), (s).end()
#define so(V) sort(ALL(V))
#define rev(V) reverse(ALL(V))
#define uni(v) v.erase( unique(ALL(v)) , v.end());
#define PAU system("pause")

typedef long long unsigned int llu;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<bool> vb;
typedef vector<vi> vvi;
typedef vector<vll> vvll;
typedef vector<vb> vvb;
const double EPS = 1e-9;
const int MOD = 1e9 + 7;
const int INF = (1 << 28);
const double PI = acos(-1);

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	int N;
	cin >> N;
	int n = 3;
	int d = 3;
	bool ok = false;
	if (N == 1) {
		cout << "Yes" << endl;
		cout << 2 << endl;
		cout << "1 1" << endl;
		cout << "1 1" << endl;
		PAU;
		return 0;
	}
	while (n <= N) {
		if (n == N) {
			ok = true;
			break;
		}
		n += d;
		d++;
	}
	if (!ok) {
		cout << "No" << endl;
		PAU;
		return 0;
	}
	d--;//数列一つ一つの要素数。
	
	if (N == 3) {
		cout << "Yes" << endl;
		cout << 3 << endl;
		cout << "2 1 2" << endl;
		cout << "2 1 3" << endl;
		cout << "2 2 3" << endl;
		PAU;
		return 0;
	}
	int cnt = 1;
	vvi Ans;
	vi S;
	REP(i, d) {
		S.push_back(i + 1);
	}
	Ans.push_back(S);
	S = vi();
	FOR(i, d, 2 * d) {
		S.push_back(i);
	}
	int nxt = 2 * d;
	Ans.push_back(S);
	REP(i, N * 2 / d - 2) {
		S = vi();
		S.push_back(i + 1);
		FOR(j, 1, cnt + 1) {
			S.push_back(Ans[j][cnt]);
		}
		REP(i, d - cnt - 1) {
			S.push_back(nxt);
			nxt++;
		}
		Ans.push_back(S);
		cnt++;
	}
	cout << "Yes" << endl;
	cout << N * 2 / d << endl;
	REP(i, SZ(Ans)) {
		cout << d;
		for (int s : Ans[i]) {
			cout << " " << s;
		}
		cout << endl;
	}
	PAU;
	return 0;
}
