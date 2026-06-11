#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;

int main(){
	int N;
	scanf("%d", &N);
	int x[N], y[N], h[N];
	for (int i = 0; i < N; ++i){
		scanf("%d %d %d", x + i, y + i, h + i);
	}
	for (int C_X = 0; C_X <= 100; ++C_X){
		for (int C_Y = 0; C_Y <= 100; ++C_Y){
			int isnt0 = 0;
			while(!h[isnt0]) isnt0++;
			int h_top = h[isnt0] + abs(x[isnt0] - C_X) + abs(y[isnt0] - C_Y);
			bool flag = true;
			for (int i = 0; i < N; ++i){
				if(max(h_top - abs(x[i] - C_X) - abs(y[i] - C_Y), 0) != h[i]){
					flag = false;
					break;
				}
			}
			if(flag){
				printf("%d %d %d\n", C_X, C_Y, h_top);
				return 0;
			}
		}
	}
	return 0;
}