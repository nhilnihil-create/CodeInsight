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
vector<string> brd;

bool can(int a, int b) {
	rep(i,0,n) rep(j,0,n) {
		if(brd[(i+a)%n][(j+b)%n] != brd[(j+a)%n][(i+b)%n]) {
			return false;
		}
	}
	return true;
}

int main(void) {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	//freopen("in.txt", "r", stdin);
	cin >> n;
	brd.resize(n);
	rep(i,0,n) {
		cin >> brd[i];
	}
	int ret = 0;
	rep(i,0,n) {
		if(can(i,0)) {
			ret += n;
		}
	}
	cout << ret << endl;
	return 0;
}
