#include <iostream>
#include <algorithm>
#include <string.h>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;
typedef long long ll;

struct Edge {
	int v, u, w;
};

int N, M, L, LL;
//10의 n승
vector<Edge> res;
int Binary[30];

int main() {
	cin.tie(NULL); cout.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> L;
	L--; LL = L;
	int cnt = 0;
	while (L) {
		Binary[cnt++] = (L % 2);
		L /= 2;
	}

	if (LL == (1 << cnt) - 1) {
		for (int i = 1; i <= cnt; ++i) {
			res.push_back({ i, i + 1, 0 });
			res.push_back({ i, i + 1, (1 << (i - 1)) });
		}
		cout << cnt + 1 << ' ' << res.size() << '\n';
		for (auto ans : res) {
			cout << ans.v << ' ' << ans.u << ' ' << ans.w << '\n';
		}
		return 0;
	}
	N = cnt;
	for (int i = 1; i < N; ++i) {
		res.push_back({ i, i + 1, 0 });
		res.push_back({ i, i + 1, (1 << (i - 1)) });
	}


	res.push_back({ 1, N, LL });
	for (int i = 0; i < N-1; ++i) {
		if (Binary[i]) {
			LL -= (1 << i);
			res.push_back({ i+1, N, LL });
		}
	}

	cout << N << ' ' << res.size() << '\n';
	for (auto ans : res) {
		cout << ans.v << ' ' << ans.u << ' ' << ans.w << '\n';
	}

	return 0;
}