#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define rep(pos, len) for(int pos=0;pos<len;pos++)
#define repp(pos, len) for(int pos=1;pos<=len;pos++)

#define INF 987654321
#define IINF 2987654321987654321
#define MOD 100000

struct Edge {
	int x, y, val;
};

int main() {
	int l; scanf("%d", &l);
	if(l <= 50) {
		int n = 2, m = l;
		printf("%d %d\n", n, m);
		for(int i = 0; i < l; i++)
			printf("%d %d %d\n", 1, 2, i);
		return 0;
	}

	vector<int> v;
	vector<Edge> E;
	int k = l;
	while(k) v.push_back(k), k /= 2;
	v.pop_back();
	reverse(v.begin(), v.end());
	int cur = 1;
	for(int i = 0; i < (int)v.size(); i++) {
		if(i == 0) {
			for(int t = 0; t < v[0]; t++)
				E.push_back({cur, cur+1, t});
			cur++;
			continue;
		}

		if(v[i] & 1) E.push_back({1, cur+1, v[i]-1});
		E.push_back({cur, cur+1, 0});
		E.push_back({cur, cur+1, v[i]/2});
		cur++;
	}

	printf("%d %d\n", cur, (int)E.size());
	for(auto e : E) printf("%d %d %d\n", e.x, e.y, e.val);
}