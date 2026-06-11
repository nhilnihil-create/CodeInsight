#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, t;
	scanf("%d %d", &n, &t);
	int minimo = 10000;
	for(int i = 0; i<n; i++){
		int ci, ti;
		scanf("%d %d", &ci, &ti);
		if (ti<=t) minimo = min(minimo, ci);
	}
	if (minimo == 10000) puts("TLE");
	else printf("%d\n", minimo);
}