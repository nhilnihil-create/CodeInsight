#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n, pos[200005];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		int px;
		scanf("%d", &px);
		pos[px] = i;
	}
	int res = 1, run = 1;
	for(int i = 2; i <= n; i++){
		if(pos[i] > pos[i - 1]){
			run++;
			res = max(res, run);
		}else{
			run = 1;
		}
	}
	printf("%d\n", n - res);
	return 0;
}