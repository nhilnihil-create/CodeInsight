#include <bits/stdc++.h>
using namespace std;

signed main(){
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if(abs(a - c) <= d || (abs(a - b) <= d && abs(b - c) <= d)){
		printf("Yes\n");
	}
	else{
		printf("No\n");
	}
	return 0;
}