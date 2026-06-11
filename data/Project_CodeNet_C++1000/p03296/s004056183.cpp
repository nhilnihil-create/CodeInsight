#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n, pv, run;

int main(){
	scanf("%d", &n);
	int ans = 0;
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		if(x == pv){
			run++;
		}else{
			ans += run / 2;
			pv = x;
			run = 1;
		}
	}
	printf("%d\n", ans + run / 2);
	return 0;
}