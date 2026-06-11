#include <bits/stdc++.h>
using namespace std;

#define int long long
#define FOR(i,a,b) for(int (i)=(a);(i)<(b);(i)++)
#define REP(i,n) FOR(i,0,n)

typedef long long ll;

template <class T = ll> T in() { T x; cin >> x; return (x); }

vector<int> A[100005];
int color[100005];
bool Odd = false;
int num = 1;

void odd(int pos) {
	for (auto x : A[pos]) {
		if (color[x] == -1) {
			color[x] = (color[pos] + 1) % 2;
			if (color[x] == 0) num++;
			odd(x);
		} else if (color[x] == color[pos]) {
			Odd = true;
		}
	}
	return;
}

signed main() {
	int n,m;
	cin >> n >> m;
	REP (i,m) {
		int x = in()-1,y = in()-1;
		A[x].push_back(y);
		A[y].push_back(x);
	}
	REP (i,100005) {
		color[i] = -1;
	}

	color[0] = 0;
	odd(0);

	int ans = 0;
	if (Odd) {
		ans = n * (n - 1) / 2 - m;
	} else {
		ans = (n - num) * num - m;
	}
	cout << ans << endl;
}