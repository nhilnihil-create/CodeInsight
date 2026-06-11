#include <bits/stdc++.h>
#define all(X) (X).begin(),(X).end()
#define rall(X) (X).rbegin(),(X).rend()
#define pub push_back
#define puf push_front
#define pob pop_back
#define pof pop_front
#define ff first
#define ss second
#define P 1000000007
#define in(x, a, b) (a <= x && x < b)

using namespace std;
using ll = long long;
typedef pair<int, int> ii;
typedef vector<ii> vii; 
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
const ll inf = 1000000001, INF = (ll)1e18 + 1;

int ceil(int a, int b) {
	return (a + b - 1) / b;
}

void solve() {
	int d, g;
	cin >> d >> g;
	
	vi p(d), c(d);
	for(int i = 0; i < d; i++) cin >> p[i] >> c[i];
	
	int ans = inf;
	for(int msk = 0; msk < (1 << d); msk++) {
		int num = 0, score = 0;
		for(int i = 0; i < d; i++) if(msk & (1 << i)) num += p[i], score += c[i] + (i + 1) * 100 * p[i];
		for(int i = d - 1; i >= 0 && score < g; i--) {
			if(msk & (1 << i)) continue;
			num += min(p[i], ceil(g - score, 100 * (i + 1)));
			score += 100 * (i + 1) * min(p[i], ceil(g - score, 100 * (i + 1)));
		}
		
		if(score >= g) ans = min(ans, num);
	} 
	
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}