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
	int ans = 0;
	int tmp;
	int n;
	cin >> n;
	vector<int> h(n+1);
	REP1(i, n) cin >> h[i];
	h[0] = 0;
	REP1(i, 100){
		REP1(j, n){
			if(h[j-1] < i && h[j] >= i) ans ++;
		}
	}
	cout << ans << endl;
}