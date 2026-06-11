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
	int n, z, w;
	cin >> n >> z >> w;
	
	vi a(n);
	for(int i = 0; i < n; i++) cin >> a[i];
	
	if(n == 1) cout << abs(a[n - 1] - w) << endl;
	else cout << max(abs(a[n - 2] - a[n - 1]), abs(a[n - 1] - w));
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}