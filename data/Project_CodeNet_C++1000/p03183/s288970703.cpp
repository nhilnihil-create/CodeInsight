#include <bits/stdc++.h>
#define ll long long
#define ld long double
#define pii pair<int, int>
#define piil pair<pii, ll>
#define F first
#define S second
#define pb push_back

const int SMAX = 10001;

using namespace std;

int n, ein[1010];
piil wsv[1010];
ll dp[SMAX];
vector<int> g[1010];



int main(){

	cin >> n;
	for(int i=1; i<=n; i++) cin >> wsv[i].F.F >> wsv[i].F.S >> wsv[i].S;

	for(int i=1; i<=n; i++){
		for(int j=i+1; j<=n; j++){
			int w1 = wsv[i].F.F, s1 = wsv[i].F.S;
			int w2 = wsv[j].F.F, s2 = wsv[j].F.S;
			if(w1 <= s2 && w2 <= s1){
				if(s2-w1 > s1-w2){
					ein[i]++;
					g[j].pb(i);
				} else if(s2-w1 < s1-w2){
					ein[j]++;
					g[i].pb(j);
				}
			} else if(w1 <= s2){
				ein[i]++;
				g[j].pb(i);
			} else if(w2 <= s1){
				ein[j]++;
				g[i].pb(j);
			}
		}
	}

	vector<int> ord, z;

	for(int i=1; i<=n; i++) if(!ein[i]) z.pb(i);

	for(unsigned int i=0; i<z.size(); i++){
		ord.pb(z[i]);
		for(int j : g[z[i]]){
			ein[j]--;
			if(!ein[j]) z.pb(j);
		}
	}

	for(int i=0; i<n; i++){
		int c = ord[i];
		for(int j=wsv[c].F.F; j<SMAX; j++){
			int nx = min(j-wsv[c].F.F, wsv[c].F.S);
			if(dp[j]) dp[nx] = max(dp[nx], dp[j]+wsv[c].S);
		}
		dp[wsv[c].F.S] = max(dp[wsv[c].F.S], wsv[c].S);
	}

	ll ans = 0;
	for(int i=0; i<SMAX; i++) ans = max(ans, dp[i]);

	cout << ans << endl;

	return 0;
}
