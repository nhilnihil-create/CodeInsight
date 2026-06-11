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
	int n;
	cin >> n;
	
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	vi pre(n), suf(n);
	pre[0] = a[0];
	for(int i = 1; i < n; i++) {
		pre[i] = __gcd(pre[i - 1], a[i]);
	}
	
	suf[n - 1] = a[n - 1]; 
	for(int i = n - 2; i >= 0; i--) {
		suf[i] = __gcd(suf[i + 1], a[i]);
	}
	
	int ans = pre[n - 1];
	ans = max(ans, pre[n - 2]);
	ans = max(ans, suf[1]);
	for(int i = 1; i < n - 1; i++) {
		ans = max(ans, __gcd(pre[i - 1], suf[i + 1]));
	}
	
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}