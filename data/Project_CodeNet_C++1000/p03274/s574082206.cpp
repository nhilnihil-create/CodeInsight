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
	int ans = INTINF;
	int tmp;
	int n, k;
	cin >> n >> k;
	int x[n+1]={}, rw[n+1]={};
	REP1(i, n){
		cin>> x[i];
		rw[i]=rw[i-1]+x[i];
	}
	for(int i = k; i<=n; i++){
		if(x[i] >= 0 && x[i-k+1] >= 0){
			ans = min(ans, x[i]);
		}
		else if(x[i] < 0 && x[i-k+1] < 0){
			ans = min(ans, 0- x[i-k+1]);
		}
		else {
			ans = min(ans, min(x[i], -x[i-k+1]) + x[i] - x[i-k+1]);
		}
	}
	cout << ans << endl;
}