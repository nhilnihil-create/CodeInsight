#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

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

    vector<int> p(N);

    for(int i = 0; i < N; i++) {
        cin >> p[i];
        p[i]--;
    }

    UnionFind uf(N);

    for(int i = 0; i < M; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        uf.unite(x, y);
    }

    vector<bool> checker(N);
    vector<vector<int> > A(N);
    vector<vector<int> > B(N);

    for(int i = 0; i < N; i++) {
        int x = uf.find(i);
        checker[x] = true;
        A[x].push_back(i);
        B[x].push_back(p[i]);
    }

    int ans = 0;

    for(int i = 0; i < N; i++) {
        if(!checker[i]) continue;
        sort(A[i].begin(), A[i].end());
        sort(B[i].begin(), B[i].end());
        int a = 0;
        int b = 0;
        while(a < A[i].size() && b < B[i].size()) {
            if(A[i][a] == B[i][b]) {
                ans++;
                a++;
                b++;
            } else if(A[i][a] < B[i][b]) a++;
            else b++;
        }
    }

    cout << ans << endl;
}