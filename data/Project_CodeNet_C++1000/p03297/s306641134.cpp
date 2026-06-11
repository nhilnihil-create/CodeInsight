#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<set>
#include<queue>
#include<stack>
using namespace std;
#define int long long
#define vel vector<long long>
#define vvel vector<vel>
#define rep(i,n) for(long long i=0;i<n;i++)
#define rp(i,n) for(long long i=1;i<n;i++)
#define sor(v) sort(v.begin(),v.end())
#define mmax(a,b) a=max(a,b)
#define mmin(a,b) a=min(a,b)
#define mkp make_pair
#define pin pair<int,int>
#define V vector
long long p = 1000000007;
vel rui(19, 1);
vel par;
int root(int ser) {
	if (par[ser] == -1) { return ser; }
	int ans = root(par[ser]);
	par[ser] = ans;
	return ans;
}
bool marge(pin a) {
	int x = root(a.first);
	int y = root(a.second);
	if (x != y) {par[x] = y;}
	return x != y;
}
int gcd(int a, int b) {
	if (a < b) { swap(a, b); }
	if (b == 0) { return a; }
	return gcd(b, a%b);
}
signed main() {
	int t; cin >> t;
	V<string> s(t);
	rep(i, t) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		if (d >= b && a >= b) {
			if (c >= b) { s[i]="Yes"; }
			else {
				int x = a % b;
				int gc = gcd(b, d);
				int pl = (b - 1 - x) / gc;
				x += pl * gc;
				if (x > c) { s[i]="No"; }
				else {s[i]="Yes"; }
			}
		}
		else { s[i]="No"; }
	}
	rep(i, t) { cout << s[i] << endl; }
	return 0;
}
