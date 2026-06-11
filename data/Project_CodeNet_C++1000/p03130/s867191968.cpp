#include <bits/stdc++.h>
 
#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;
typedef long long ll;

const int maxn = 205;

int deg[5];

signed main(void){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	int M = 3;
	while (M--){
		int u, v;
		cin >> u >> v;
		deg[u]++; deg[v]++;
	}
	int res = 0;
	for (int i=1; i<=4; ++i)
		if (deg[i] == 1) ++res;
	if (res <= 2) cout << "YES";
	else cout << "NO";
}
