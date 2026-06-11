//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define INF 0x6fffffff
#define INFL 0x6fffffffffffffffLL
ll n , m;
vector<int> k(10) , p(10);
vector<vector<int>> s(11, vector<int>(11));

int onswitch(int onoff, int ik) {
	int ret = 0;
	for(int i=0;i<k[ik];i++) {
		if ((onoff & (1 << ( (int)s[ik][i]-1)) ) != 0) ret++;
	}
	return ret;
}
int main() {
	int		a,b,c,h,i,j,l,x,y;
	int		ans = 0;
	cin >> n >> m;

	for(i=0;i<m;i++) {
		cin >> k[i];
		for(j=0;j<k[i];j++) {
			cin >> s[i][j];
		}
	}
	for(i=0;i<m;i++) cin >> p[i];

	for(i=0;i<(1<<n);i++) {
		bool f = true;
		for(j=0;j<m;j++) {
			if ( (onswitch(i,j) %2) != p[j]) f = false;
		}
		if (f) ans++;
	}
	//vector<ll>	aa(n);
	//for(i=0;i<n;i++) cin >> aa[i];
	//vector<ll>	dp(n+1,INFL);
	//vector<vector<ll>>	dp2(x , vector<ll>(y,INFL));

	cout << ans << endl;
	return 0;
}
