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
	int ans = 0;
	int tmp;
	int a, b, c, x;
	cin >> a >> b >> c >> x;
	REP(i, a+1){
		REP(j, b+1){
			int z = x - 500 * i - 100 * j;
			if(z >= 0 && z % 50 == 0 && z / 50 <= c) ans ++;
		}
	}
	cout << ans << endl;
}