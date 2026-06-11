#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll N = 1005;
const ll dx[4] = {1, 0, -1, 0};
const ll dy[4] = {0, 1, 0, -1};
const char typ[5] = "RULD";

ll arm[45], m;
ll n, x[N], y[N];

void solve (ll X, ll Y, ll I) {
	ll CX = 0, CY = 0, CI = -1;
	for(ll i=0;i<4;i++) {
		ll NX = dx[i]*arm[I], NY = dy[i]*arm[I];
		if(CI == -1 || abs(NX-X)+abs(NY-Y) < abs(CX-X)+abs(CY-Y)) {
			CX = NX;
			CY = NY;
			CI = i;
		}
	}
	printf("%c",typ[CI]);
	if(I) solve(X-CX, Y-CY, I-1);
}

int main()
{
	scanf("%lld",&n);
	for(ll i=1;i<=n;i++) {
		scanf("%lld%lld",&x[i],&y[i]);
		if(abs(x[i]+y[i])%2 != abs(x[1]+y[1])%2) {
			puts("-1");
			return 0;
		}
	}
	if(abs(x[1]+y[1])%2) {
		m = 39;
		arm[0] = 1;
		arm[1] = 2;
		for(ll i=1;i<=19;i++) {
			arm[2*i] = arm[2*i-1];
			arm[2*i+1] = arm[2*i]*3;
		}
	}
	else {
		m = 40;
		arm[0] = 1;
		arm[1] = 1;
		for(ll i=1;i<=20;i++) {
			arm[2*i] = arm[2*i-1]*3;
			arm[2*i+1] = arm[2*i];
		}
	}
	printf("%lld\n",m);
	for(ll i=m;i--;) {
		printf("%lld ",arm[i]);
	}
	puts("");
	for(ll i=1;i<=n;i++) {
		solve(x[i], y[i], m-1);
		puts("");
	}
}
