#include <bits/stdc++.h>
using namespace std;

const int MAXN = 105;

int n, a[MAXN], b[MAXN];
bool mark[MAXN];

int main(){
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
		scanf("%d", &a[i]);
	
	for(int i = 0; i < n; i++){
		bool found = false;
		for(int j = n - 1; j >= 0; j--){
			if(mark[j])continue;
			
			int c = 1;
			for(int k = 0; k < j; k++)
				c += mark[k];
			
			if(c == a[j]){
				b[i] = a[j];
				mark[j] = true;
				found = true;
				break;
			}
		}
		
		if(!found){
			printf("-1\n");
			return 0;
		}
	}
	
	for(int i = 0; i < n; i++)
		printf("%d\n", b[i]);
	
    return 0;
}
