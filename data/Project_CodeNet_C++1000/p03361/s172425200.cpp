#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


#define SIZE 55

int H,W;
int diff_row[4] = {-1,0,0,1},diff_col[4] = {0,-1,1,0};
char buf[SIZE][SIZE];


bool rangeCheck(int row,int col){

	return row >= 0 && row <= H-1 && col >= 0 && col <= W-1;
}

int main(){

	scanf("%d %d",&H,&W);

	for(int row = 0; row < H; row++){

		scanf("%s",buf[row]);
	}

	for(int row = 0; row < H; row++){
		for(int col = 0; col < W; col++){
			if(buf[row][col] == '.')continue;

			int count = 0;

			for(int i = 0; i < 4; i++){

				int adj_row = row+diff_row[i];
				int adj_col = col+diff_col[i];

				if(!rangeCheck(adj_row,adj_col))continue;

				if(buf[adj_row][adj_col] == '#'){
					count++;
					break;
				}
			}
			if(count == 0){

				printf("No\n");
				return 0;
			}
		}
	}

	printf("Yes\n");

	return 0;
}
