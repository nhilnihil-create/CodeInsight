#include<iostream>
#include<stdio.h>
#include<string>
#include<vector>
#include<map>
#include<tuple>
#include<algorithm>
#include<cmath>
#include<limits>
#include<set>
#include<deque>
#include<queue>
using namespace std;
#define int long  long int
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
typedef pair<int, int>P;
const int MOD = 1e9 + 7;
//const int MOD = 998244353;
const int INF = 1e18;
const long double PI = (acos(-1));


int N, A, B, C;
vector<int>l;
//A 0 B 1 C 2 使わないなら 3
int ans = INF;

void dfs(vector<int>v) {
	if (v.size() == N) {
		int a, b, c;
		int cnta, cntb, cntc;
		a = b = c = cnta = cntb = cntc = 0;
		rep(i, N) {
			if (v[i] == 0)a += l[i];
			else if (v[i] == 1)b += l[i];
			else if (v[i] == 2)c += l[i];
			if (v[i] == 0)cnta++;
			else if (v[i] == 1)cntb++;
			else if (v[i] == 2)cntc++;
		}
		if (cnta && cntb && cntc) {
			int MP = abs(a - A) + abs(b - B) + abs(c - C);
			MP += 10 * (cnta + cntb + cntc - 3);
			chmin(ans, MP);
		}
		return;
	}

	rep(i, 4) {
		vector<int>nv = v;
		nv.push_back(i);
		dfs(nv);
	}
}

signed main() {
	cin >> N >> A >> B >> C;
	l.resize(N);
	rep(i, N)cin >> l[i];
	vector<int>v;
	dfs(v);
	cout << ans << endl;
}