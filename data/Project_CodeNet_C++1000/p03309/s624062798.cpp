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

int main() {
	ll n;
	cin >> n;
	vector<ll> a(n);
	rep(i, n){
		cin >> a[i];
		a[i] = a[i] - i - 1;
	}
	sort(all(a));
	ll ave = a[n/2];
	ll ans = 0;
	rep(i, n)ans += abs(a[i]-ave);
	cout << ans << endl;
}
