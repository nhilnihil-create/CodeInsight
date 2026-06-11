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

void solve() {
	int m, k;
	cin >> m >> k;
	
	if(m == 0) {
		if(k == 0) cout << "0 0" << endl;
		else cout << -1 << endl;
		return;
	}
	
	if(m == 1) {
		if(k == 0) cout << "0 0 1 1" << endl;
		else cout << -1 << endl;
		return;
	}
	
	if(k >= (1 << m)) {
		cout << -1 << endl;
		return;
	}
	
	for(int i=(1<<m)-1; i>=1; --i)
		printf("%d ",i^k);
	printf("%d ", k);
	for(int i=1; i<=(1<<m)-1; ++i)
		printf("%d ",i^k);
	printf("%d ", k);
	puts("");
	return;
}

int main() {
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}