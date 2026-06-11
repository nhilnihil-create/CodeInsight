#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;
typedef vector<int> vi;

#define pb push_back
#define eb emplace_back
#define mp make_pair
#define fi first
#define se second
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<(n);i++)
#define ALL(c) (c).begin(),(c).end()

const int MN = 200010;

int N, M;
string s;
vi g[MN];
int num[MN][2];
bool er[MN];

int main() {
	cin >> N >> M >> s;

	rep(i, M) {
		int a, b;
		scanf("%d %d", &a, &b);
		--a; --b;

		if (s[b] == 'A') {
			++num[a][0];
		} else {
			++num[a][1];
		}

		if (s[a] == 'A') {
			++num[b][0];
		} else {
			++num[b][1];
		}	

		g[a].pb(b); g[b].pb(a);
	}

	queue<int> que;

	int dec = N;

	rep(i, N) {
		if (num[i][0] == 0 || num[i][1] == 0) {
			que.push(i);
			er[i] = 1;
		}
	}

	while (!que.empty()) {
		--dec;
		int v = que.front(); que.pop();
		int c = (s[v] != 'A');

		for (int to : g[v]) {
			if (--num[to][c] == 0 && !er[to]) {
				que.push(to);
				er[to] = 1;
			}
		}
	}

	puts(dec > 0 ? "Yes" : "No");

	return 0;
}