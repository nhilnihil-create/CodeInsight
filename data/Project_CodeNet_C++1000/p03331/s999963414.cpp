#include"bits/stdc++.h"

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i, n) for (int i = 1; i <= (int)(n); i++)
#define all(v) v.begin(), v.end()
#define rall(v) v.rbegin(), v.rend()
using namespace std;
using ll = long long;
using pi = pair<int, int>;
const ll INF = 1LL << 60;

int main() {
	int n, a, b,tmp=0,ans=1e9;
	cin >> n;
	REP(i, n/2) {
		a = n - i;
		b = i;
		tmp = 0;
		while(a >= 10){
			tmp += a % 10;
			a /= 10;
		}
		tmp += a;
		while (b >= 10) {
			tmp += b % 10;
			b /= 10;
		}
		tmp += b;
		ans = min(ans, tmp);
	}
	cout << ans << endl;
	return 0;
}

