#include<stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);
	int L, R;
	int l=-1e9, r=1e9;
	for (int i = 0; i < m; i++){
		scanf("%d %d", &L, &R);
		L = max(L, l);
		l = L;
		R = min(r, R);
		r = R;
	}
	if (R - L + 1 < 0) {
		printf("0");
		return 0;
	}
	printf("%d",R-L+1);
	
}