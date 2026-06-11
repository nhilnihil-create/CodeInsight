#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
	ll x, y, z, p;
	cin >> x >> y >> z >> p;
	vector<ll> a(x), b(y), c(z);
	rep(i,x) cin >> a[i];
	rep(i,y) cin >> b[i];
	rep(i,z) cin >> c[i];
	sort(a.rbegin(), a.rend());
	sort(b.rbegin(), b.rend());
	sort(c.rbegin(), c.rend());
	vector<ll> ans;
	rep(i,x)rep(j,y)rep(k,z){
		if((i+1)*(j+1)*(k+1)<=p) ans.push_back(a[i]+b[j]+c[k]);
		else break;
	}
	sort(ans.rbegin(), ans.rend());
	rep(i,p) cout << ans[i] << endl;
}