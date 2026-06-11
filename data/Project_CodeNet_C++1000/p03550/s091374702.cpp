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

const int Xplayer = 0;
const int Yplyaer = 1;
int n, z, w;
ll a[2050];

ll cache[2050][2];
ll solve(int pos, int player) {
	if(pos == n-1) {
		return abs(a[n-1] - a[n-2]);
	}

	ll& ret = cache[pos][player];
	if(ret != -1) return ret;
	ret = (pos > 0 ? abs(a[n-1] - a[pos-1]) : abs(a[n-1] - w));

	if(player == Xplayer) {
		rep(i,pos+1,n) {
			ret = max(ret, solve(i,Yplyaer));
		}
	} else {
		rep(i,pos+1,n) {
			ret = min(ret, solve(i,Xplayer));
		}
	}
	return ret;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n >> z >> w;
	rep(i,0,n) {
		cin >> a[i];
	}
	if(n == 1) {
		cout << abs(a[0] - w) << '\n';
		return 0;
	}
	memset(cache, -1, sizeof(cache));
	cout << solve(0,Xplayer) << '\n';
	return 0;
}
