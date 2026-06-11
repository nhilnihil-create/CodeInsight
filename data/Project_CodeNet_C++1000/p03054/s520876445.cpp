#include"bits/stdc++.h"
using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;i++)
const long long mod = 1000000007;
const long long inf = 1ll << 61;
typedef pair<int, int> P;
typedef pair<int,P> PP;
struct edge { int to; int cost; };

signed main() {
	int h, w, n; cin >> h >> w >> n;
	int sr, sc; cin >> sr >> sc;
	string s, t; cin >> s >> t;
	int ur = 1, dr = h, uc = 1, dc = w;
	for (int i = n - 1; i >= 0; i--) {
		if (t[i] == 'L'&&1<dc&&dc < w)dc++;
		if (t[i] == 'R'&&w>uc&&uc > 1)uc--;
		if (t[i] == 'U'&&1<dr&&dr < h)dr++;
		if (t[i] == 'D'&&h>ur&&ur > 1)ur--;
		
		if (s[i] == 'L')uc++;
		if (s[i] == 'R')dc--;
		if (s[i] == 'U')ur++;
		if (s[i] == 'D')dr--;
		//cout << ur << dr << uc << dc << endl;
	}
	if (uc <= sc&&sc <= dc&&ur <= sr&&sr <= dr)puts("YES");
	else puts("NO");
	//cout << ur << dr << uc << dc << endl;
}