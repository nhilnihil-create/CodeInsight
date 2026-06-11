#include <bits/stdc++.h>
using namespace std;

int n;

int main(){
	scanf("%d", &n);
	
	if(n % 2 == 0){
		printf("%d\n", n * (n - 2) / 2);
		for(int i = 1; i <= n; i++){
			for(int j = i + 1; j <= n; j++){
				if(i + j == n + 1)continue;
				printf("%d %d\n", i, j);
			}
		}
	}else{
		printf("%d\n", (n - 1) * (n - 3) / 2 + n - 1);
		for(int i = 1; i <= n - 1; i++){
			for(int j = i + 1; j <= n; j++){
				if(i + j == n)continue;
				printf("%d %d\n", i, j);
			}
		}
	}
	
    return 0;
}
