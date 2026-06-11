//高知能系Vtuberの高井茅乃です。
//Twitter: https://twitter.com/takaichino
//YouTube: https://www.youtube.com/channel/UCTOxnI3eOI_o1HRgzq-LEZw

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define INF 1999999999
#define REP(i,n) for(int i=0;i<n;i++)
#define REP1(i,n) for(int i=1;i<=n;i++)
#define MODA 1000000007 

int main() {
	int ans = INF;
	int tmp;
	int a, b, c;
	cin >> a >> b >> c;
	int x, y;
	cin >> x >> y;
	int mi = max(x, y);
	for(int i = 0; i <= mi; i++){
		ans = min(ans, c * i * 2 + a * max(0, x - i) + b * max(0, y - i));
	}

	cout << ans << endl;
}