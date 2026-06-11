#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < n; i++)
int n, a, b, s, e;
int main(){
	scanf("%d%d%d", &n, &a, &b);
	n -= a;b--;
	if(b>n || n>(long long)a*b) return 0*puts("-1");
	rep(i,a){
		s += (b == 0 ? 0 : i<n/b ? b : i == n/b ? n%b : 0) + 1;
		for(int i = s; i > e; i--) printf("%d%s", i, s==n+a && i-1==e ? "\n" : " ");
		e = s;
	}
}