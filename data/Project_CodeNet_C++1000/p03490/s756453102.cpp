#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(long long i=0;i<x;i++)
#define repn(i,x) for(long long i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())
vector<pair<string,P> >vec;

map<ll, bool> dpx[8001], dpy[8001];

void solve(string s, long long x, long long y){
	ll state = 0;
	dpx[0].insert(make_pair(0, true));
	dpy[0].insert(make_pair(0, true));
	ll c = 0, idx = 0, idy = 0;
	for (ll i = 0; i < s.length(); i++) {
		if (s[i] == 'F') c++;
		if ((s[i] == 'T' || i == s.length()-1) && state == 0) {
			dpx[idx+1].insert(make_pair(c, true));
			state = 1;
			c = 0;
			idx++;
		} else if ((s[i] == 'T' || i == s.length()-1) && state == 1) {
			for (auto y : dpy[idy]){
				// cout << state << " " << y.first << " " << y.second << " " << c << endl;
				dpy[idy+1].insert(make_pair(y.first-c, true));
				dpy[idy+1].insert(make_pair(y.first+c, true));
			}
			state = 2;
			c = 0;
			idy++;
		} else if ((s[i] == 'T' || i == s.length()-1) && state == 2) {
			for (auto x : dpx[idx]){
				// cout << state << " " << x.first << " " << x.second << " " << c << endl;
				dpx[idx+1].insert(make_pair(x.first-c, true));
				dpx[idx+1].insert(make_pair(x.first+c, true));
			}
			state = 1;
			c = 0;
			idx++;
		}
	}
	// repn(i,idx) {
	// 	for (auto x : dpx[i]){
	// 		cout << i << " " << x.first << " " << x.second << " " << dpx[i][x.first] << endl;
	// 	}
	// }
	// cout << endl;
	// repn(i,idy) {
	// 	for (auto x : dpy[i]){
	// 		cout << i << " " << x.first << " " << x.second << endl;
	// 	}
	// }
	// cout << dpx[idx][x] << " " << dpy[idy][y] << " " << (dpx[idx][x] && dpy[idy][y]) << endl;
	if (dpx[idx][x] && dpy[idy][y]) cout << "Yes" << endl; else cout << "No" << endl;
}

int main(){	
	string s;
	long long x;
	long long y;
	cin >> s;
	scanf("%lld",&x);
	scanf("%lld",&y);
	solve(s, x, y);
	return 0;
}

