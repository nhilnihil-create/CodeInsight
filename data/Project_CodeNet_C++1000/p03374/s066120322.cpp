#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
#include<iomanip>
#include<map>
#include<set>
#include<vector>
#define FAST ios::sync_with_stdio(false);cin.tie(0);cout.tie(0)
typedef long long ll;
const int inf = 0x3f3f3f3f;
const int maxn = (int)1e6 + 5;
const int mod = (int)1e9 + 9;
using namespace std;
 
ll x[maxn];
int v[maxn];
ll c[maxn], cc[maxn];
ll cmx[maxn], ccmx[maxn];
 
int main()
{
	//input
	int n; ll C; scanf("%d %lld", &n, &C);
	for(int i = 1; i <= n; i++) scanf("%lld %d", &x[i], &v[i]);
	//solve
	for(int i = 1; i <= n; i++){
		c[i] = c[i-1] + v[i] - (x[i] - x[i-1]);
		cmx[i] = max(cmx[i-1], c[i]);
	}
	x[n+1] = C;
	for(int i = n; i >= 1; i--){
		cc[n-i+1] = cc[n-i] + v[i] - (x[i+1] - x[i]);
		ccmx[n-i+1] = max(ccmx[n-i], cc[n-i+1]); 
	}
	ll ans = 0;
	for(int i = 0; i <= n; i++){
		ans = max(ans, c[i] - x[i] + ccmx[n-i]);
		ans = max(ans, cc[i] - (C - x[n-i+1]) + cmx[n-i]);
	}
	//output
	printf("%lld\n", ans);
	return 0;
}
