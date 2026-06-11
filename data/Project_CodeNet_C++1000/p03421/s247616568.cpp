#include <cstdio>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;

int main()
{
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);
	if(a+b>n+1 || (long long int)a*(long long int)b<(long long int)n){
		printf("%d\n", -1);
	}else if(b==1){
		for(int i=1; i<=n; i++){
			printf("%d ", i);
		}
		printf("\n");
	}else{
		int q=(n-a)/(b-1), r=(n-a)%(b-1);
		for(int i=1; i<=q; i++){
			for(int j=0; j<b; j++){
				printf("%d ", i*b-j);
			}
		}
		if(r!=0){
			for(int j=0; j<r+1; j++){
				printf("%d ", q*b+r+1-j);
			}
			for(int i=q*b+r+2; i<=n; i++){
				printf("%d ", i);
			}
		}else{
			for(int i=q*b+1; i<=n; i++){
				printf("%d ", i);
			}
		}
		printf("\n");
	}
	return 0;
}