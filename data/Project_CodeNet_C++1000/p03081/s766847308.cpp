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
	int n, q; cin >> n >> q;
	string s; cin >> s;
	s = "*" + s + "*";
	vector<char> t(q), d(q);
	REP(i, q) cin >> t[i] >> d[i];
	int fr = n+1, fl = 0;
	for(int i = q-1; i >= 0; i--){
		if(d[i] == 'R' && s[fr-1] == t[i]) fr--;
		if(d[i] == 'R' && s[fl] == t[i]) fl--;
		if(d[i] == 'L' && s[fl+1] == t[i]) fl++;
		if(d[i] == 'L' && s[fr] == t[i]) fr++;
	}
	cout << max(fr - fl - 1, 0) << endl;
}