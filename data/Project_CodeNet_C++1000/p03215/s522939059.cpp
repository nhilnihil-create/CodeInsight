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
	ll n, k;
	cin >> n >> k;
	vector<ll> a(n+1);
	REP1(i, n) cin >> a[i];
	ll rw[n+1] ={};
	REP1(i, n) rw[i] = a[i] + rw[i-1];
	vector<ll> pa;
	REP1(i, n) REP(j, i) pa.push_back(rw[i]-rw[j]);
	sort(pa.begin(), pa.end());
	ll co;
	//REP(i, pa.size()) cout << pa[i] << endl;
	for(int i = 62; i >= 0; i--){
		co = 0;
		REP(j, pa.size()){
			if(((ans & pa[j]) == ans) && ((ll)1<<i & pa[j])){
				co++;
			}
		}
		if(co >= k) ans |= (ll)1 << i;
	}
	cout << ans << endl;
}