#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define f first
#define s second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

typedef long double ld;

int main(){ _

	int n; cin >> n;
	vector<ld> p(n);
	for(auto& i : p) cin >> i;
	
	vector<vector<ld>> memo(2, vector<ld>(n+1, 0)); // prob heads
	memo[0][0] = memo[1][0] = 1;
		
	for(int i=0; i<n; i++) {
		memo[i&1][i] = memo[(i&1)^1][i];

		for(int j=0; j <= n; j++) {
			memo[i&1][j] = memo[(i&1)^1][j]*(1.0-p[i]);
			
			if(j) memo[i&1][j] += memo[(i&1)^1][j-1]*p[i];
		}
	}

	ld ans = 0;
	for(int i=0; i<=n; i++) if(n-i < i) ans += memo[(n-1)&1][i];
	cout << fixed << setprecision(10);
	
	cout << ans << endl;

	return 0;
}
