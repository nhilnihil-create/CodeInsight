#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n, arr[105], out[105];

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		scanf("%d", &arr[i]);
	}
	for(int i = n; i >= 1; i--){
		bool ok = false;
		for(int j = i; j > 0; j--){
			if(arr[j] == j){
				out[i] = j;
				for(int k = j; k < i; k++){
					arr[k] = arr[k + 1];
				}
				ok = true;
				break;
			}
		}
		if(!ok){
			printf("-1\n");
			return 0;
		}
	}
	for(int i = 1; i <= n; i++){
		printf("%d\n", out[i]);
	}
	return 0;
}