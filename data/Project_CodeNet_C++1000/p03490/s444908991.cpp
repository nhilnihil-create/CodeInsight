#include <bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false), cin.tie(0)
#define REP(i, n) for (int i = 0; i < n; i++)
#define FOR(i, a, b) for (int i = a; i < b; i++)
#define ALL(x) (x).begin(), (x).end()
#define dump(x) cout << (x) << endl
#define LMAX 9223372036854775807LL
#define LMIN -9223372036854775807LL
using ll = long long;
template<typename T>
using vec = vector<T>;
using P = pair<ll, ll>;
template <typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
	fill((T *)array, (T *)(array + N), val);
}

const ll INF = 1e16;
const ll MOD = 1e9 + 7;
//int dx[4] = {1,0,-1,0};
//int dy[4] = {0,1,0,-1};
//ll pas[51][52];

bool dpx[8030][20002] = {},dpy[8030][20002] = {};

signed main(){
	IOS;
	ll x, y;
	string s;
	cin >> s >> x >> y;
	ll n = s.size();
	vec<ll> vx,vy;
	ll c = 0;
	bool isx = true;
	REP(i,n){
		if(s[i] == 'T'){
			if(isx && c != 0){
				vx.push_back(c);
				c = 0;
			}
			else if(c != 0){
				vy.push_back(c);
				c = 0;
			}
			isx = !isx;
		}
		else c++;
	}
	if(isx){
		vx.push_back(c);
	}
	else{
		vy.push_back(c);
	}
	const ll cnt = 10000;
	ll tx = vx.size();
	ll ty = vy.size();
	dpx[0][cnt] = true;
	dpy[0][cnt] = true;
	for(int i = 0;i < tx;i++){
		for(int j = 0;j <= 20000;j++){
			if(i == 0 && s[0] == 'F'){
				if(j - vx[i] >= 0)dpx[i + 1][j] = dpx[i][j - vx[i]];
			}
			else {
				if(j - vx[i] >= 0)dpx[i + 1][j] = dpx[i][j - vx[i]];
				if(j + vx[i] < 20000)dpx[i + 1][j] |= dpx[i][j + vx[i]];
			}
		}
	}
	for(int i = 0;i < ty;i++){
		for(int j = 0;j <= 20000;j++){
			if(j - vy[i] >= 0)dpy[i + 1][j] = dpy[i][j - vy[i]];
			if(j + vy[i] < 20000)dpy[i + 1][j] |= dpy[i][j + vy[i]];
		}
	}
	if(dpx[tx][x + cnt] && dpy[ty][y + cnt])dump("Yes");
	else dump("No");
}