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

struct edge {
	int from, to, weight;
};

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	int L, n, m;
	int back_up_L;
	cin >> L;
	back_up_L = L;
	n = 0;
	while(L) {
		L >>= 1;
		n++;
	}
	n--;
	L = back_up_L;

	vector<edge> ret;
	rep(i,0,n) {
		ret.pb({i,i+1,1<<i});
		ret.pb({i,i+1,0});
	}
	int now = (1<<n);
	rep(i,0,n) {
		if(L & (1<<i)) {
			int j = (1<<(i+1))-1;
			int w = L & ~j;
			ret.pb({i,n,w});
		}
	}
	cout << n+1 << " " << ret.size() << endl;
	rep(i,0,sz(ret)) {
		edge e = ret[i];
		cout << e.from+1 << " " << e.to+1 << " " << e.weight << '\n';
	}
	return 0;
}
