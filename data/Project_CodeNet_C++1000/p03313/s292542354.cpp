#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
using ll = long long;
int n, a[1<<18], a2[1<<18], t;
int main(){
	scanf("%d", &n);
	rep(i,1<<n) scanf("%d", a+i);
	rep(i,n) rep(j,1<<n) if(j>>i&1){
		if(a[j] > a[j^(1<<i)]) a2[j] = max(a2[j], a[j^(1<<i)]);
		else{
			a2[j] = max(a[j], a2[j^(1<<i)]);
			a[j] = a[j^(1<<i)];
		}
	}
	rep(i,1<<n) if(i) printf("%d\n",t = max(t,a[i]+a2[i]));
}