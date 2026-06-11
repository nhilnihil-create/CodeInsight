#include <bits/stdc++.h>
using namespace std;

int u[65], v[65], w[65];

int main (){
	int L, n = 0, m = 0, i, d;
	scanf("%d", &L);
	d = L; while(d){
		d /= 2;
		++n;
	}
	for(i = 0; i < n - 1; ++i){
		if(i < n - 1){
			u[m] = i, v[m] = i + 1, w[m++] = 0;
			u[m] = i, v[m] = i + 1, w[m++] = (1 << i);
		}
		if(L & (1 << i)){
			u[m] = i, v[m] = n - 1, w[m++] = ((1 << n) - (1 << (i + 1))) & L;
		}
	}
	printf("%d %d\n", n, m);
	for(i = 0; i < m; ++i)
		printf("%d %d %d\n", u[i] + 1, v[i] + 1, w[i]);
	return 0;
}
