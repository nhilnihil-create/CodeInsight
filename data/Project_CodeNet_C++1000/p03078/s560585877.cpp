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
	int x, y, z, k;
	cin >> x >> y >> z >> k;
	
	vector<ll> a(x), b(y), c(z);
	for(int i = 0; i < x; i++) cin >> a[i];
	for(int i = 0; i < y; i++) cin >> b[i];
	for(int i = 0; i < z; i++) cin >> c[i];
	
	vector<ll> ab;
	for(int i = 0; i < x; i++)
		for(int j = 0; j < y; j++)
			ab.pub(a[i] + b[j]);
			
	sort(all(ab));
	reverse(all(ab));
	sort(all(c));
	reverse(all(c));
	
	priority_queue<pair<ll, ii>> q;
	for(int i = 0; i < ab.size(); i++) {
		q.push({ab[i] + c[0], {i, 0}});
	}
	
	int taken = 0;
	while(!q.empty() && taken < k) {
		cout << q.top().ff << endl;
		taken++;
		ii state = q.top().ss;
		q.pop();
		if(state.ss + 1 < z) {
			q.push({ab[state.ff] + c[state.ss + 1], {state.ff, state.ss + 1}});
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
	solve();
    return 0;
}