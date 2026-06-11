#include<iostream>
#include<string>
#include<vector>
#include<queue>
#include<algorithm>
#include<map>
#include<set>
#include<cmath>
typedef long long ll;
#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define sz(a) (int)a.size()
using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<ll> abc, abmc, ambc, ambmc, mabc, mabmc, mambc, mambmc;
	rep(i, n) {
		ll x, y, z;
		cin >> x >> y >> z;
		abc.pb(x + y + z);
		abmc.pb(x + y - z);
		ambc.pb(x - y + z);
		ambmc.pb(x - y - z);
		mabc.pb(-x + y + z);
		mabmc.pb(-x + y - z);
		mambc.pb(-x - y + z);
		mambmc.pb(-x - y - z);
	}
    sort(abc.begin(),abc.end());
  sort(abmc.begin(),abmc.end());
  sort(ambc.begin(),ambc.end());
  sort(ambmc.begin(),ambmc.end());
  sort(mabc.begin(),mabc.end());
  sort(mabmc.begin(),mabmc.end());
  sort(mambc.begin(),mambc.end());
  sort(mambmc.begin(),mambmc.end());
  
  
	ll ans = 0;
	ll ansi = 0;
	rep(i, m) {
		ansi += abc[n-1-i];
	}
	ans = max(ans, ansi);


	ansi = 0;
	rep(i, m) {
		ansi += abmc[n-1-i];
	}
	ans = max(ans, ansi);


	ansi = 0;
	rep(i, m) {
		ansi += ambc[n-1-i];
	}
	ans = max(ans, ansi);


	ansi = 0;
	rep(i, m) {
		ansi += ambmc[n-1-i];
	}
	ans = max(ans, ansi);


	ansi = 0;
	rep(i, m) {
		ansi += mabc[n-1-i];
	}
	ans = max(ans, ansi);


	ansi = 0;
	rep(i, m) {
		ansi += mabmc[n-1-i];
	}
	ans = max(ans, ansi);


	ansi = 0;
	rep(i, m) {
		ansi += mambc[n-1-i];
	}
	ans = max(ans, ansi);


	ansi = 0;
	rep(i, m) {
		ansi += mambmc[n-1-i];
	}
	ans = max(ans, ansi);

	cout << ans << endl;
}