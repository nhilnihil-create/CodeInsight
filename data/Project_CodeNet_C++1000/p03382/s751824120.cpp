#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main(){
	int n; scanf("%d", &n);
	int maxj = 0;
	for (int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		maxj = max(maxj, a[i]);
	}
	int minj = 0x3f3f3f3f, pos;
	for (int i = 0; i < n; i++){
		if (abs(a[i] - (maxj + 1) / 2) < minj && a[i] < maxj) minj = abs(a[i] - (maxj + 1) / 2), pos = a[i];
	}
	printf("%d %d\n", maxj, pos);
	return 0;
}
