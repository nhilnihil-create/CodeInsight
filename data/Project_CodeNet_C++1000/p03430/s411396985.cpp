#include <bits/stdc++.h>

using namespace std;

int D[333][333][333];
char str[333];
int n, k;

int f(int l, int r, int t)
{
	if(l >= r) return l == r;
	
	if(D[l][r][t]) return D[l][r][t];
	
	int ret = max(f(l+1, r, t), f(l, r-1, t));
	if(str[l] == str[r]) ret = max(ret, f(l+1, r-1, t) + 2);
	else if(t < k) ret = max(ret, f(l+1, r-1, t+1) + 2);
	
	return D[l][r][t] = ret;
}

int main()
{
	scanf("%s%d", str, &k);
	
	for(;str[n];n++);
	
	printf("%d\n", f(0, n-1, 0));
	
	return 0;
}