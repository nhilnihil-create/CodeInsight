#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int n, h, w, ans, a, b;
int main(){
	scanf("%d%d%d", &n, &h, &w);
	rep(i,n){
		scanf("%d%d", &a, &b);
		if(a >= h && b >= w) ans++;
	}
	printf("%d\n", ans);
}