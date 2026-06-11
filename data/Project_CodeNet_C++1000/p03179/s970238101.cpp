#pragma comment(linker, "/stack:20000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx")
#include <stdio.h>
#include <bits/stdc++.h>

using namespace std;

#include <x86intrin.h>
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
template <typename T> using ordered_set = tree<T, null_type, std::less<T>, rb_tree_tag, tree_order_statistics_node_update>;

#define all(x) x.begin(), x.end()

#define mp make_pair
#define in insert
#define er erase
#define con continue
#define pb push_back
#define sc scanf
#define pr printf
#define ub upper_bound
#define lb lower_bound
#define s second
#define f first
#define int long long

const long long infl = 1e18; 
const int N = 3e5 + 300, N2 = 2e3, inf = 1e9 + 200, mod = 1e9 + 7;

int n;
string s;
int p[3002][3002], d[3002][3002];

int get(int l, int r, int i){
//	cout << l << " " << r << endl;
	if (l > r) return 0;
	return (p[i][r] - p[i][l - 1] + mod) % mod;
}

main (){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	for (int i = 1; i <= n; i++){
		if (i == 1){
			/*d[1][1] = 1;
			p[1][1] = 1;*/
			for (int j = 1; j <= n; j++){
				d[i][j] = 1;
			}
			for (int j = 1; j <= n; j++){
				(p[i][j] = p[i][j - 1] + d[i][j]) %= mod;
			}
		}
		else{
			for (int j = 1; j <= n; j++){
				if (s[i - 2] == '<'){
					d[i][j] = get(1, j - 1, i - 1);
					
			 	}
			 	else{
			 		d[i][j] = get(j, i - 1, i - 1);
			 	}
			}
			for (int j = 1; j <= n; j++){
				(p[i][j] = p[i][j - 1] + d[i][j]) %= mod;
			}
		}
		//if (i == 2)return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++){
		(ans += d[n][i]) %= mod;
	}
	cout << ans;
	return 0;
}










