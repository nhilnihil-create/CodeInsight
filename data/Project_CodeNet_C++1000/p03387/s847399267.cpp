#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
	int g[5];
	rep(i, 3) cin>>g[i];
	sort(g, g+3);
	int ma=g[2], md=g[1], mi=g[0];
	int cnt = 0;
	cnt += (ma-md) / 2;
	cnt += (ma-mi) / 2;
	bool isMd = (ma-md) % 2 == 0;
	bool isMi = (ma-mi) % 2 == 0;
	if (isMd && !isMi) cnt += 2;
	if (!isMd && isMi) cnt += 2;
	if (!isMd && !isMi) cnt++;
	cout << cnt << endl;
	return 0;
}