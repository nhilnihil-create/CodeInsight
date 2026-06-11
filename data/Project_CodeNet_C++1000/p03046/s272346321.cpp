#include <bits/stdc++.h>
using namespace std;
int n, m, i, j, k, x, y;
int main(){
	scanf("%d%d", &n, &m);
	if(m >= (1<<n)) printf("-1\n");
	else if(m == 0){
		for(i=0; i<=(1<<n)-1; i++){
			printf("%d %d ", i, i);
		}
	}
	else if(n < 2) printf("-1\n");
	else{
		for(i=0; i<=(1<<n)-1; i=++x){
			if((j=i^m) < i) continue;
			for(x=i+1; (y=x^m)<x; x++);
			printf("%d %d %d %d %d %d %d %d ", i, j, x, y, j, i, y, x);
		}
	}
	return 0;
}