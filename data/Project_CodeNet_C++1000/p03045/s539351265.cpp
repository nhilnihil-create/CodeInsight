#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<double, double> p;

#define MOD 1000000007

class UnionFind {
private:
	vector<ll> parents;
	vector<ll> ranks;

public:
	vector<ll> sizes;

	UnionFind(ll s): parents(s), ranks(s), sizes(s, 1) {
		for(ll i = 0; i < s; i++) parents[i] = i;
	}

	int find(ll x) {
		if(parents[x] == x) return x;
		else return parents[x] = find(parents[x]);
	}

	void unite(ll x, ll y) {
		x = find(x);
		y = find(y);
		if(x == y) return;

		if(ranks[x] < ranks[y]) {
			parents[x] = y;
			sizes[y] += sizes[x];
		} else {
			parents[y] = x;
			sizes[x] += sizes[y];
			if(ranks[x] == ranks[y]) ranks[x]++;
		}
	}

	bool same(ll x, ll y) {
		return find(x) == find(y);
	}
};

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M;
    cin >> N >> M;

    UnionFind uf(N);

    for(int i = 0; i < M; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        uf.unite(x, y);
    }

    vector<bool> c(N);

    int ans = 0;

    for(int i = 0; i < N; i++) {
        int x = uf.find(i);
        if(c[x]) continue;
        ans++;
        c[x] = true;
    }

    cout << ans << endl;
}