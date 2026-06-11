#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <queue>
#include <stack>
#include <map> 
#include <set>
#include <string>
#include <functional>
#include <list>
#include <random>
#include <time.h>
#include <iomanip>
#include <assert.h>
#include <numeric>
#define int long long
#define ll long long
#define double long double
#define mod 1000000007
#define MAXN (int)1e+5 * 2+1
#define LL_MAX 9223372036854775807	//ない環境用
#define LL_HALFMAX 9223372036854775807 / 2	//ない環境用
#define MIN -(9223372036854775807 / 2)
#define INF 9223372036854775807 / 2
#define REP(i,a,n) for(int i=(a); i<(int)(n); i++)
#define rep(i,n) REP(i,0,n)
#define FOR(it,c) for(__typeof((c).begin()) it=(c).begin(); it!=(c).end(); ++it)
#define ALLOF(c) (c).begin(), (c).end()
#define REPS(i,x) for(int i=1;i<=(int)(x);i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define RREPS(i,x) for(int i=((int)(x));i>0;i--)
#define repl(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define mp make_pair


using namespace std;

std::mt19937 mt((int)time(0));

int dx[4] = { 0, 1, 0, -1 }; // x軸方向への変位
int dy[4] = { 1, 0, -1, 0 }; // y軸方向への変位

using Weight = int;
using Flow = int;
struct Edge {
	int src, dst;
	Weight weight;
	Flow cap;
	Edge() : src(0), dst(0), weight(0) {}
	Edge(int s, int d, Weight w) : src(s), dst(d), weight(w) {}
};
using Edges = std::vector<Edge>;
using Graph = std::vector<Edges>;
using Array = std::vector<Weight>;
using Matrix = std::vector<Array>;

void add_edge(Graph &g, int a, int b, Weight w = 1) {
	g[a].emplace_back(a, b, w);
	g[b].emplace_back(b, a, w);
}
void add_arc(Graph &g, int a, int b, Weight w = 1) { g[a].emplace_back(a, b, w); }

vector<pair<char, char>> inst;

int N, Q;
string s;
int go[2000000];

void doQuery(pair<char, char> q) {
	for (int i = 0; i < N; i++) {
		if (go[i] == -1 || go[i] == N) continue;

		if (s[go[i]] == q.first) {
			if (q.second == 'L') {
				go[i]--;
			}
			else {
				go[i]++;
			}
		}
	}
}

int doInstOne(vector<pair<char, char>> inst, int index) {
	int now = index;
	for (auto q : inst) {
		if (q.first == s[now]) {
			if (q.second == 'L') now--;
			else now++;
		}
		if (now == -1 || now == N) {
			break;
		}
	}
	return now;
}

void printgo() {
	for (int i = 0; i < N; i++) {
		cout << go[i] << " ";
	}
	cout << "\n";
}

signed main() {

	cin >> N >> Q >>s;

	for (int i = 0; i < N; i++) {
		go[i] = i;
	}

	//愚直解
	for (int i = 0; i < Q; i++) {
		char t, d;
		cin >> t >> d;
		inst.push_back(make_pair(t, d));
	}
	/*
	printgo();
	for (auto p : inst) {
		
		doQuery(p);
		printgo();
	}

	int ans = 0;
	for (int i = 0; i < N; i++) {
		//if (go[i] >= 0 && go[i] < N) ans++;
		cout << doInstOne(inst, i) << "\n";
	}
	cout << ans << "\n";
	*/

	//少なくとも一つ-1に到達しない/Nに到達しないゴーレムがあることを保証
	int first = doInstOne(inst, 0), last = doInstOne(inst, N - 1);
	if (first == N || last == -1) {
		cout << 0 << "\n";
		return 0;
	}

	int high = 0, low = 0;
	//下限(-1に到達しない最大のインデックス)をもとめる
	
	int ub = N - 1, lb = 0;
	while (ub - lb > 1) {
		int mid = (lb + ub ) / 2;
		int midValue = doInstOne(inst, mid);
		if (midValue != -1) {
			ub = mid;
		}
		else {
			lb = mid;
		}
	}
	low = ub;

	ub = N - 1, lb = 0;
	while (ub - lb > 1) {
		int mid = (lb + ub ) / 2;
		int midValue = doInstOne(inst, mid);
		if (midValue != N) {
			lb = mid;	//[mid,ub)
		}
		else {
			ub = mid;	//[ub,mid)
		}
	}
	high = lb;
	if (doInstOne(inst, low) == N || doInstOne(inst, high) == -1) {
		cout << 0 << "\n";
		return 0;
	}

	if (doInstOne(inst, 0) != -1) {
		low = 0;
	}
	if (doInstOne(inst, N - 1) != N) {
		high = N - 1;
	}

	cout << high - low + 1 << "\n";





	return 0;
}