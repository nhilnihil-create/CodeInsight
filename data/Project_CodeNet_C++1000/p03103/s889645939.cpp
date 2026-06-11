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
	ll n, m, a, b;
	cin >> n >> m;
	vector< pair<ll, ll>> ed;
	REP(i, n){
		cin >> a >> b;
		//ed.push_back(make_pair(a, b));
		ed.emplace_back(a, b);
	}
	sort(ed.begin(), ed.end());
	ll rest = m;
	for(int i = 0; rest > 0; i++){
		ans += ed[i].first * min(ed[i].second, rest);
		rest -= ed[i].second;
	}
	cout << ans << endl;
}