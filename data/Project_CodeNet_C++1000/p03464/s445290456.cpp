//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	int tmp;
	int k;
	cin >> k;
	vector<ll> a(k);
	REP(i, k) cin >> a[i];
	ll mi = 2, ma = 2;
	for(int i = k-1; i >= 0; i--){
		ll shomi = (mi + a[i] - 1) / a[i];
		mi = a[i] * shomi;
		ll shoma = ma / a[i];
		ma = a[i] * shoma + a[i] - 1;
	}
	if(mi <= ma) cout << mi << " " << ma << endl;
	else cout << -1 << endl;
}