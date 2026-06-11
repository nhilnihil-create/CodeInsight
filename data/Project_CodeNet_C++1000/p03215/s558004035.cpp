#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
const int MX = 1005;
int n, k, e, b;
ll a[MX], c[MX*MX/2], ans;
int main(){
	scanf("%d%d", &n, &k);
	rep(i,n){
		scanf("%lld", a+i+1);
		a[i+1] += a[i];
		rep(j,i+1) c[e++] = a[i+1] - a[j];
	}
	sort(c, c+e);
	for(int i = 39; i >= 0; i--){
		int tb = (int)(lower_bound(c+b, c+e, ans + (1LL<<i)) - c);
		if(e - tb < k){
			ll t1[MX*MX/2] = {}, t2[MX*MX/2] = {};
			for(int j = b; j < tb; j++) t1[j-b] = c[j];
			for(int j = tb; j < e; j++) t2[j-tb] = c[j] ^ (1LL<<i);
			merge(t1, t1+tb-b, t2, t2+e-tb, c+b);
		}else{
			ans += 1LL<<i;
			b = tb;
		}
	}
	printf("%lld\n", ans);
}