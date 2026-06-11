#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int N,C;
int D[30][30];
int table[500][500];
int COST[3][30];


int main(){

	scanf("%d %d",&N,&C);

	for(int from = 0; from < C; from++){
		for(int to = 0; to < C; to++){

			scanf("%d",&D[from][to]);
		}
	}

	for(int row = 0; row < N; row++){
		for(int col = 0; col < N; col++){

			scanf("%d",&table[row][col]);
			table[row][col]--;
		}
	}

	for(int i = 0; i <= 2; i++){//剰余
		for(int to_C = 0; to_C < C; to_C++){ //新しい色

			int tmp = 0;

			for(int row = 0; row < N; row++){
				for(int col = 0; col < N; col++){
					if((row+col)%3 != i)continue;

					tmp += D[table[row][col]][to_C];
				}
			}
			COST[i][to_C] = tmp;
			//printf("COST[%d][%d]:%d\n",i,to_C,tmp);
		}
	}

	int ans = BIG_NUM;

	if(N == 1){

		for(int a = 0; a < C; a++){
			ans = min(ans,COST[0][a]);
		}

	}else{

		for(int a = 0; a < C; a++){
			for(int b = 0; b < C; b++){
				if(a == b)continue;
				for(int c = 0; c < C; c++){
					if(c == a || c == b)continue;

					ans = min(ans,COST[0][a]+COST[1][b]+COST[2][c]);
				}
			}
		}
	}

	printf("%d\n",ans);

	return 0;
}
