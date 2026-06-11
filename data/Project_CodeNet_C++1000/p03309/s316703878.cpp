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
//	freopen("subtask_1_02.txt", "r", stdin);
	int n;
	cin >> n;
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	for(int i = 0; i < n; i++) {
		a[i] -= i + 1;
	}
	
	sort(all(a));
	ll total = 0;
	for(int i = 0; i < n; i++) total += a[i];
	
	ll sum = 0, ans = INF;
	for(int i = 0; i < n; i++) {
		ll b = a[i];
		sum += a[i];
		if(i + 1 < n && a[i] == a[i + 1]) continue;
		ll res = b * (i + 1) - sum + (total - sum) - (n - i - 1) * b;
		ans = min(ans, res);
	}
	
	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}