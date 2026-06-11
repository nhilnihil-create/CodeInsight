#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef set<int> si;
typedef set<ll> sl;
typedef pair<int,int> pii;
#define rep(i,a,b) for(int i=(a); i<(b); ++i)
#define per(i,a,b) for(int i=(b)-1; i>=(a); --i)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()
#define mp make_pair
#define pb push_back
#define F first
#define S second

int n;
vi v;
map<int, int> record;

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n;
	v.resize(n);
	rep(i,0,n) {
		cin >> v[i];
		record[v[i]] = i;
	}

	int r = 0;
	vector<bool> visited(n+1, false);

	for(int x = 1; x <= n; ++x) {
		if(visited[x]) continue;

		int y = x;
		int idx = record[y];
		while(y < n + 1 && record[y] >= idx) {
			visited[y] = true;
			idx = record[y];
			y++;
		}
		r = max(r, y - x);
	}

	cout << n - r << endl;
	return 0;
}