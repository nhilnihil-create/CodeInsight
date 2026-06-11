// 失敗するからこそ そこから立ち向かって行く強さがあってそんな強さが本当の強さだと私は思うから
// ぜったいあきらめない
#if defined(DAIJOBU)
#include "/home/ichigo/includes.hpp"
#include "/home/ichigo/debug.hpp"
#define deb(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#include <bits/stdc++.h>
#define deb(x...)
#endif
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long lint;
typedef vector<lint> vlint;
typedef vector<vlint> vvlint;
typedef pair<lint, lint> plint;
typedef double ld;

template<class T> bool chmin(T &a, T b) { return a > b ? (a = b, true) : false; }
template<class T> bool chmax(T &a, T b) { return a < b ? (a = b, true) : false; }

char grid[100][100];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
bool used[100][100];
int dist[100][100], n, m;

bool ok(int x, int y){
	if(x >= 0 && x < n && y >= 0 && y < m && grid[x][y] != '#')return true;
	return false;
}

void bfs(int x, int y){
	used[x][y] = true;
	dist[x][y] = 0;
	queue<pii> q;
	q.push({x, y});
	while(!q.empty()){
		auto u = q.front();
		q.pop();
		forn(i, 4){
			int tx = u.fi + dx[i];
			int ty = u.se + dy[i];
			if(!used[tx][ty] && ok(tx, ty)){
				used[tx][ty] = true;
				dist[tx][ty] = dist[u.fi][u.se] + 1;
				q.push({tx, ty});
			}
		}
	}
			
}

int main() {
    ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	vector<int> a;
	a.pb(0);
	forn(i, n){
		int x;
		cin >> x;
		a.pb(x);
	}
	a.pb(0);
	int tot = 0;
	forn(i, a.size() - 1)tot += abs(a[i] - a[i + 1]);
	for1(i, n){
		int cur = tot;
		cur -= abs(a[i] - a[i - 1]);
		cur -= abs(a[i] - a[i + 1]);
		cur += abs(a[i - 1] - a[i + 1]);
		cout << cur << '\n';
	}
	return 0;
}

