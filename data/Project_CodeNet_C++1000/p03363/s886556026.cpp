//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF INT_MAX
#define LLINF LLONG_MAX
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007
#define MODB  998244353 

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

int main() {
	ll ans = 0;
	ll tmp;
	int n; cin >> n;
	vector<ll> a(n);
	cin >> a;
	map<ll, int> m;
	m[0]++;
	tmp = 0;
	ll rw[n] = {};
	REP(i, n){
		tmp += a[i];
		m[tmp]++;
		rw[i] = tmp;
	}
	ans += m[0];
	REP(i, n){
		//cout << rw[i] << endl;
		ans += m[rw[i]] - 1;
	}
	cout << ans / 2 << endl;
}