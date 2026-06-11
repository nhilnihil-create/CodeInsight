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
    ll ans = 0, x = 0;
    int tmp;
    ll n, k;
	cin >> n >> k;
	vector<ll> a(n);
	REP(i, n) cin >> a[i];
	for (int i = 40; i >= 0; i--)
	{
		ll now = (ll)1 << i;
		if(x + now > k) continue;
		tmp = 0;
		REP(j , n){
			if(now & a[j]) tmp ++;
		}
		//cout << now << " " << tmp << " " << i << endl;
		if(tmp > n / 2) continue;
		else x += now; 
	}
	//cout << x << endl;
	REP(i, n){
		ans += x ^ a[i];
	}
    cout << ans << endl;
}