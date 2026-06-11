#include<iostream>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<utility>
#include<algorithm>
using namespace std;
#define ll long long
#define vel vector<ll>
#define vvel vector<vel>
#define vvvel vector<vvel>
#define veb vector<bool>
#define pin pair<ll,ll>
#define mkp make_pair
#define mot pair<D,D>//time,dist
#define path pair<ll,int>//cost,to
#define int long long
using namespace std;
vvel ta_min(0);
vvel ta_max(0);
int leth = 1024 * 512;
int p = 1000000007;
vel par;
vel dis;
int n;
void mmax(ll &a, ll b) { a = max(a, b); }
void mmin(ll &a, ll b) { a = min(a, b); }
pin root(int ser) {
	if (par[ser] == -1) {return mkp(ser,0);}
	pin x=root(par[ser]);
	x.second += dis[ser];
	par[ser] = x.first;
	dis[ser] = x.second;
	return x;
}
void uni(int a, int b,int d) {
	pin p1 = root(a);
	pin p2 = root(b);
	int a1 = p1.first;
	int b1 = p2.first;
	if (a1 != b1) {
		par[b1] = a1;
		dis[b1] = d + dis[a] - dis[b];
	}
}
bool issame(int x, int y) {
	return root(x).first == root(y).first;
}
void ref(int &x) { x = x % p; x = (x + p) % p; }
signed main() {
	cin >> n; int m; cin >> m;
	par = vel(n, -1);
	dis = vel(n,0);
	for (int i = 0; i < m; i++) {
		int l, r; cin >> l >> r; l--; r--;
		int d; cin >> d;
		pin l1=root(l);
		pin r1= root(r);
		if (l1.first != r1.first ) { uni(r, l, d); }
		else {
			if (dis[r] + d == dis[l]) { uni(r, l, d); }
			else { cout << "No" << endl; return 0; }
		}
	}
	cout << "Yes" << endl;
	return 0;
}