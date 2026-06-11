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
	int n, m;
	cin >> n >> m;
	vector<ll> x(m);
	REP(i, m) cin >> x[i];
	sort(x.begin(), x.end());
	vector<ll> dx;
	REP(i, m-1){
		dx.push_back(x[i+1] - x[i]);
	}
	sort(dx.begin(), dx.end());
	ans = x[m-1] - x[0];
	REP(i, n-1) if(m-2-i >= 0)ans -= dx[m-2-i];
	cout << ans << endl;
}