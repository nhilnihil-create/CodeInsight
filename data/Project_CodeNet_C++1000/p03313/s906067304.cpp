#include<bits/stdc++.h>
#define Rint register int
using namespace std;
const int N = 1 << 18;
int n, a[N], b[2][N], ans[N];
inline void add(int i, int val){
	if(val >= b[0][i]) b[1][i] = b[0][i], b[0][i] = val;
	else if(val >= b[1][i]) b[1][i] = val;
}
inline void insert(int i, int j){
	add(i, b[0][j]); add(i, b[1][j]);
}
inline void FWT(){
	for(Rint i = 0;i < n;i ++)
		for(Rint S = 0;S < (1 << n);S ++) if(!((S >> i) & 1))
			insert(S | (1 << i), S);
}
int main(){
	scanf("%d", &n);
	for(Rint i = 0;i < (1 << n);i ++) scanf("%d", a + i), add(i, a[i]); FWT();
	ans[0] = b[0][0] + b[1][0];
	for(Rint i = 1;i < (1 << n);i ++){
		ans[i] = max(ans[i - 1], b[0][i] + b[1][i]);
		printf("%d\n", ans[i]);
	}
}