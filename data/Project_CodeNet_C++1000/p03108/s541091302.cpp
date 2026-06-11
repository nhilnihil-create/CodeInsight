#include <iostream>
#include <fstream>
#include <set>
#include <map>
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <functional>
#include <algorithm>
#include <climits>
#include <cmath>
#include <iomanip>
using namespace std;
#define ll long long int
#define rep(i,n) for( int i = 0; i < n; i++ )
#define rrep(i,n) for( int i = n; i >= 0; i-- )
#define REP(i,s,t) for( int i = s; i <= t; i++ )
#define RREP(i,s,t) for( int i = s; i >= t; i-- )
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define INF 2000000000
#define mod 1000000007
#define INF2 1000000000000000000
#define int long long
struct UnionFind {
	vector<int> par;
	UnionFind(int x) : par(x, -1) {}
	void init(int x) { par.assign(x, -1); }
	int root(int x) {
		if (par[x] <= -1) return x;
		else return root(par[x]);
	}
	bool issame(int x, int y) {
		return root(x) == root(y);
	}
	bool merge(int x, int y) {
		x = root(x); y = root(y);
		if (x == y) return false;
		if (par[x] > par[y]) swap(x, y);
		par[x] += par[y];
		par[y] = x;
		return true;
	}
	int size(int x) {
		return -par[root(x)];
	}
};
int ans[100010];
signed main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    int a[100010], b[100010];
    rep(i, M) {
        cin >> a[i] >> b[i];
        a[i]--; b[i]--;
    }
    int sum = N * (N - 1) / 2;
    UnionFind UF(N);
    RREP(i, M - 1, 0) {
        ans[i] = sum;
        int diff = -UF.size(a[i]);
        if(!UF.issame(a[i], b[i])) {
            sum -= UF.size(a[i]) * UF.size(b[i]);
            UF.merge(a[i], b[i]);   
        }     
        
    }
    rep(i, M) cout << ans[i] << endl;


    return 0;
}
