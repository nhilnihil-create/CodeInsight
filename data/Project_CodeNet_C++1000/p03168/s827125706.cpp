#include <bits/stdc++.h>
using namespace std;
 
int n;
double dp[4096][4096], p[4096];
int vis[4096][4096];
 
double calc(int pos, int heads) {
    if(heads < 0) return 0;
    double &y = dp[pos][heads];
    if(vis[pos][heads]) return y;
    vis[pos][heads] = 1;
    if(pos == 0) return y = (heads == 0);
    return y = p[pos] * calc(pos-1, heads-1) + (1-p[pos])*calc(pos-1, heads);
}
 
int main() {
	cin >> n;
	for(int i=1; i<=n; ++i) {
	    cin >> p[i];
	}
	double ans = 0;
	for(int i=(n+1)/2; i<=n; ++i) {
	    ans += calc(n, i);
	}
	cout << fixed << setprecision(11) << ans << endl;
	return 0;
}