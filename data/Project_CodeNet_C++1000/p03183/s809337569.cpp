#include <bits/stdc++.h>
#define ll long long
#define pb push_back
#define mp make_pair
using namespace std;
const int maxn = 20100;

class block {
public:
	ll w, s, v;
};

class comparator {
public:
	bool operator()(block a, block b) {
		return a.w + a.s < b.w + b.s;
	}
};

block a[maxn];
int n;

ll dp[1010][maxn];

int main() {
	cin>>n;

	ll w, s, v;
	for(int i=1;i<=n;i++) {
		cin>>w>>s>>v;
		a[i] = {w, s, v};
	}

	sort(a+1, a+n+1, comparator());

	ll result = 0LL;
	for(int i=1;i<=n;i++) {
		for(int j=0;j<maxn;j++) {
			dp[i][j] = dp[i-1][j];
			if(j - a[i].w >= 0 && a[i].s >= j - a[i].w) {
				dp[i][j] = max(dp[i][j], dp[i-1][j-a[i].w] + a[i].v);
			}
			result = max(result, dp[i][j]);
		}
	}
	cout<<result;
}