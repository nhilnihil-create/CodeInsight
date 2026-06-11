#include <bits/stdc++.h>
using namespace std;

int n;
long double dp[4096][4096], p[4096];
int vis[4096][4096];

long double calc(int pos, int heads) {
    if(heads < 0) heads = 0;
    long double &y = dp[pos][heads];
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
	printf("%.11Lf\n", calc(n, (n+1)/2));
	return 0;
}
