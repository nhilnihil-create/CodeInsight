#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



struct Info{
	Info(int arg_from_row,int arg_from_col,int arg_to_row,int arg_to_col){
		from_row = arg_from_row;
		from_col = arg_from_col;
		to_row = arg_to_row;
		to_col = arg_to_col;
	}

	int from_row,from_col,to_row,to_col;
};


int H,W;
int table[505][505];
vector<Info> info;

int main(){

	scanf("%d %d",&H,&W);

	for(int row = 0; row < H; row++){
		for(int col = 0; col < W; col++){

			scanf("%d",&table[row][col]);
		}
	}

	int to_right = 1;
	for(int row = 0; row < H; row++){
		if(to_right){
			for(int col = 0; col <= W-2; col++){

				if(table[row][col]%2 == 1){

					table[row][col+1]++;
					info.push_back(Info(row,col,row,col+1));
				}
			}
			if(row != H-1 && table[row][W-1]%2 == 1){

				table[row+1][W-1]++;
				info.push_back(Info(row,W-1,row+1,W-1));
			}

		}else{
			for(int col = W-1; col >= 1; col--){
				if(table[row][col]%2 == 1){

					table[row][col-1]++;
					info.push_back(Info(row,col,row,col-1));
				}
			}
			if(row != H-1 && table[row][0]%2 == 1){

				table[row+1][0]++;
				info.push_back(Info(row,0,row+1,0));
			}
		}

		to_right = 1-to_right;
	}

	printf("%lld\n",info.size());

	for(int i = 0; i < info.size(); i++){

		printf("%d %d %d %d\n",info[i].from_row+1,info[i].from_col+1,info[i].to_row+1,info[i].to_col+1);
	}

	return 0;
}
