
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vi = vector<int>;
#define f(i,a,b) for (int i = a; i < b; i++)
#define pb push_back
#define all(a) a.begin(),a.end()
#define Min(a,b) a=min(a,b)

const ll oo = 1e9;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
#ifdef LOCAL
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n,m,t;
	cin>>n>>m>>t;
	vi ord[m];	
	f(i,0,m) ord[i].pb(n);
	f(_,0,t) {
		int x,y; cin>>x>>y;
		ord[--y].pb(--x);
	}
	f(i,0,m) sort(all(ord[i]));	
	int ans = oo;
	int i = 0;
	f(j,0,m) {
		auto it = upper_bound(ord[j].begin(),ord[j].end(),i);
		Min(ans,*it);
		if (*it == i+1 || j == m-1) break;
		i++;
		while (i+1<*it && *lower_bound(all(ord[j+1]),i) == i)
			i++;
		if (*lower_bound(all(ord[j+1]),i) == i)
			break;
	}
	cout << ans << endl;
	
	return 0;
}

