#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)

lli R, G, B, N;

int main(void){
	cin >> R >> G >> B >> N;
	lli ans = 0;
	rep(r, N+1){
		rep(g, N+1){
			lli b = N-r*R-g*G;
			if(b < 0) continue;
			if(b%B == 0) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}
