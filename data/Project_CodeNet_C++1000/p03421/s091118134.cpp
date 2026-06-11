#include<cstdio>
#include<algorithm>
#include<cstring>
#define rep(i, s, t) for(i = s; i <= t; ++i)
#define dep(i, s, t) for(i = s; i >= t; --i)
#define imp {puts("-1"); return 0;}

using namespace std;

const int N = 3e5 + 10;
int n, A, B;
int ans[N], l[N], r[N], pos[N];

void put(int x, int num) {
	int t, i, R = n-l[x]+1, L = R-(r[x]-l[x]);
	t = L+num;
	rep(i, l[x], r[x]-num) ans[i] = t++;
	t = L+num-1;
	rep(i, r[x]-num+1, r[x]) ans[i] = t--;
}

int main() {
	int i, t;
	scanf("%d%d%d", &n, &A, &B);
	if(A > n || B > n) imp;
	if(B > n-A+1) imp;
	if(B < ((n-1)/A+1)) imp;
	B -= ((n-1)/A+1);
	
	rep(i, 1, n) {
		pos[i] = (i-1) / A + 1;
		if(!l[pos[i]]) l[pos[i]] = i;
		r[pos[i]] = i;
	}
	dep(i, pos[n], 1) {
		t = min(B, r[i]-l[i]); B -= t;
		put(i, t);
	}
	rep(i, 1, n) printf("%d ", ans[i]); puts("");
	return 0;
}