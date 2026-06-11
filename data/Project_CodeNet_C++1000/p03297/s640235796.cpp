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

template <typename T>
std::istream& operator>>(std::istream& is, std::vector<T>& vec) {
    for (T& x: vec) { is >> x; }
    return is;
}

//gcdをユークリッド互除法で求める。O(log n)
ll euclid(ll x, ll y){
    if(min(x, y) ==  0) return max(x, y);
    else return euclid(max(x, y)% min(x, y) , min(x, y));
}
//

int main() {
	ll ans = 0;
	ll tmp;
	int n; cin >> n;
	ll a, b, c, d;
	REP(i, n){
		cin >> a >> b >> c >> d;
		
		if (a>=b && b<=d){
			if(c >= b) cout << "Yes" << endl;
			else {
				ll g = euclid(d, b);
				if(b - g + a % g <= c) cout << "Yes" << endl;
				else cout << "No" << endl;
			}
		}
		else cout << "No" << endl;
	}
	//cout << ans << endl;
}
