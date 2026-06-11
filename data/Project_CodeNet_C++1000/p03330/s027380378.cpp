#include <bits/stdc++.h>
#define ll long long
#define double long double
#define rep(i,n) for(int i=0;i<(n);i++)
#define REP(i,n) for(int i=1;i<=(n);i++)
#define mod (ll)(1e9+7)
#define inf (ll)(3e18+7)
#define pi (double) acos(-1)
#define P pair<int,int>
#define PiP pair<int,pair<int,int>>
#define all(x) x.begin(),x.end()
#define rall(x) x.rbegin(),x.rend()
using namespace std;

int n, c;
int d[100][100], a[510][510]; 
vector<int> z(100, 0), o(100, 0), t(100, 0); 

ll solve(ll c1, ll c2, ll c3){
	ll ans = 0;
	rep(i, c){
		ans += d[i][c1] * z[i];
		ans += d[i][c2] * o[i];
		ans += d[i][c3] * t[i];
	}
	return ans;
}

int main() {
	cin >> n >> c;
	rep(i, c)rep(j, c)cin >> d[i][j];	
	rep(i, n)rep(j, n){
		cin >> a[i][j];
		if((i+j+2) % 3 == 0)z[a[i][j]-1]++;
		if((i+j+2) % 3 == 1)o[a[i][j]-1]++;
		if((i+j+2) % 3 == 2)t[a[i][j]-1]++;
	}
	ll ans = inf;
	for(int i = 0; i < c; i++){
		for(int j = 0; j < c; j++){
			if(i == j)continue;
			for(int k = 0; k < c; k++){
				if(k == i || k == j)continue;
				ans = min(ans, solve(i, j, k));
			}
		}
	}
	cout << ans << endl;
}
