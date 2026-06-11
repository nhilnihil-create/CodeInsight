#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, a[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	int res = 0;
	for(int i = 0; i + 1 < n; ){
		if(a[i] == a[i + 1]){
			res++;
			i += 2;
		}else{
			i++;
		}
	}
	printf("%d\n", res);
	
	return 0;
}
