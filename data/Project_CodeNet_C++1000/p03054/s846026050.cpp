//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INTINF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	ll ans = 0;
	int tmp;
	int h, w, n;
	cin >> h >> w >> n;
	int sr, rc;
	cin >> sr >> rc;
	string s,t;
	cin>> s >> t;
	int tu = 0, td=h+1, tr=w+1, tl=0;
	bool ch = true;
	for(int i = n-1; i >= 0; i--){
		if(t[i] == 'U') td = min(td + 1, h + 1);
		if(t[i] == 'D') tu = max(tu - 1, 0);
		if(t[i] == 'R') tl = max(tl - 1, 0);
		if(t[i] == 'L') tr = min(tr + 1, w + 1);
		if(s[i] == 'U') tu = min(tu + 1, h);
		if(s[i] == 'D') td = max(td - 1, 1);
		if(s[i] == 'R') tr = max(tr - 1, 0);
		if(s[i] == 'L') tl = min(tl + 1, w);
		if(tl == w || tr == 1 || tu == h || td == 1) ch = false;
		//cout << tl << " " << tu << " " << td << " " << tr << endl;
	}
	if (tu < sr && sr < td && tl < rc && rc < tr && ch) cout << "YES" << endl;
	else cout << "NO" << endl;
	//cout << ans << endl;
}