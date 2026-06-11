#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

int man(ii a, ii b) {
	return abs(a.ff - b.ff) + abs(a.ss - b.ss);
}

void solve() {
	int h, w, d;
	cin >> h >> w >> d;
	
	vii pos(h * w + 1);
	for(int i = 0; i < h; i++) {
		for(int j = 0; j < w; j++) {
			int tmp;
			cin >> tmp;
			pos[tmp] = {i, j};
		}
	}
	
	vi dist(h * w + 1);
	for(int i = 1; i <= d; i++) {
		dist[i] = 0;
		for(int j = i + d; j <= h * w; j += d) {
			dist[j] = dist[j - d] + man(pos[j - d], pos[j]);
		}	
	}
	
	int q;
	cin >> q;
	while(q--) {
		int l, r;
		cin >> l >> r;
		cout << dist[r] - dist[l] << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}