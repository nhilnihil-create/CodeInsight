#include <bits/stdc++.h>
 
#define ll long long
#define ii pair<int, int>
#define vi vector<int>
#define vl vector<ll>
#define pb push_back
#define mp make_pair
#define mt make_tuple
#define ff first
#define ss second
#define pi 3.14159265
#define oo 1000000007
#define loo 1000000000000000007
 
using namespace std;
#define prime 1000000007
 
#define W(x) cerr << "\033[31m" << #x << " = " << x << "\033[0m" << "\n";
 
int n, m, v[10] = {0,2,5,5,4,5,6,3,7,6};
pair<ii, int> dp[10100];
ii c[10];
vi ans;
 
pair<ii, int> f(int at){
	if(at < 0) return {{-prime, -prime}, -prime};
	if(at == 0) return {{0, 0}, 0};
	if(dp[at] != mp(mp(-1, -1), -1)) return dp[at];
	pair<ii, int> res =  {{-prime, -prime}, -prime};
	for (int i = 0; i < m; ++i){
		pair<ii, int> aux = f(at-c[i].ff);
                aux.ff.ff++;
                aux.ss = at-c[i].ff;
                aux.ff.ss = c[i].ss;

		if(aux > res){
                     res = aux;
		}
	}
	return dp[at] = res;
}
 
int main(){
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; ++i){
		int x;
		scanf("%d", &x);
		c[i] = {v[x], x};
	}
	sort(c, c+m);
	for (int i = 0; i <= n; ++i){
		dp[i] = {{-1, -1}, -1};
	}
	auto a = f(n);
	int at = n;
	while(at){
		ans.pb(dp[at].ff.ss);
		at = dp[at].ss;
	}
	if(a.ff.ff != (int)ans.size()) while(1);
	// sort(ans.begin(), ans.end());
	// reverse(ans.begin(), ans.end());
	for(int l : ans) printf("%d", l);
	printf("\n");
 
	return 0;
}
