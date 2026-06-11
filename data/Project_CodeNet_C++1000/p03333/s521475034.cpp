#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
const int MX = 100005;
int n, l[MX], r[MX];
long long ans, t;
int main(){
	scanf("%d", &n);
	rep(i,n){
		scanf("%d%d", l+i, r+i);
		l[i] = -l[i];
	}
	sort(l,l+n); sort(r,r+n);
	rep(i,n){
		ans = min(ans, t + min({r[i] + l[i], r[i], l[i]}));
		t += r[i] + l[i];
	}
	printf("%lld\n", -ans*2);
}