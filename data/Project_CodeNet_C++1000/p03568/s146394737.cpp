#include <bits/stdc++.h>
using namespace std;

int a[15], n, ans;

void func(int p, int m){
	if(p == n){
		if(m == 0) ++ans;
		return;
	}
	func(p + 1, m * (1 - (a[p] & 1)));
	func(p + 1, m * (a[p] & 1));
	func(p + 1, m * (1 - (a[p] & 1)));
}

int main (){
	int i;
	scanf("%d", &n);
	for(i = 0; i < n; ++i) scanf("%d", a + i);
	func(0, 1);
	printf("%d\n", ans);
	return 0;
}
