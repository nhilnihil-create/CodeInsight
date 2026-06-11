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
	ll ans = LLINF;
	ll tmp, sol;
	int d, g; cin >> d >> g;
	int p[d] ={}, c[d] = {};
	REP(i, d) cin >> p[i] >> c[i];
	int comp[d+1] ={};
	REP(i, d){
		comp[i] = (i+1) * 100 * p[i] + c[i];
		//cout << comp[i] << endl;
	}
	REP(bi, 1 << d){
		tmp = 0;
		sol = 0;
		REP(i, d){
			if(bi & (1<<i)){
				tmp += comp[i];
				sol += p[i];
			}
		}
		//cout << bi << " " << sol << " " << tmp << " ";
		if(tmp < g){
			for(int i = d-1; i >= 0; i--){
				if(!(bi & (1<<i))){
					ll rest = (g - tmp + (i+1) * 100 - 1) / ((i+1) * 100);
					sol += rest;
					if(rest >= p[i]) sol = LLINF;
					//cout << i+1 << " " << rest << endl;
					break;
				}
			}
		}
		ans = min(ans, sol);
	}
	cout << ans << endl;
}