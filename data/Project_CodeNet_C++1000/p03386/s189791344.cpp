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
	int a, b, k;
	cin >> a >> b >> k;
	if(b-a+1 < k * 2){
		for(int i= a; i<=b; i++) cout << i << endl;
	}
	else{
		REP(i, k) cout << a + i << endl;
		for(int i= k-1; i>= 0; i--) cout << b - i << endl;
	}
	//cout << ans << endl;
}