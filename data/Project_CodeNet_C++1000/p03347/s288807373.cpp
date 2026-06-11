//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	int tmp;
	int n;
	cin >> n;
	vector<ll> a(n+1);
	a[0] = -1;
	REP1(i, n) cin >> a[i];
	ll r[n+2] = {};
	bool ch = true;
	for(int i = n; i >= 1; i--){
		if(a[i] - a[i-1] > 1) ch = false;
		r[i] = max((ll)0,r[i+1]-1);
		if(a[i] > r[i]){
			ans += a[i];
			r[i] = a[i];
		}
	}
	if (ch) cout << ans << endl;
	else cout << "-1" << endl;
	//cout << ans << endl;
}