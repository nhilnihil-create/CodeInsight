#include <iostream>
#define mod 1000000007
using namespace std;

long int dp[1000][1000];

void num_paths(int H,int W){
	
	dp[0][0] = 1;
	for(int row = 0 ; row < H ; row++){
		for(int col = 0 ; col < W ; col++){
			if(dp[row][col] >= 0){
				if(row > 0 && dp[row-1][col] > 0)
					dp[row][col] += (dp[row-1][col]%mod) ;
				if(col > 0 && dp[row][col-1] > 0)
					dp[row][col] +=  (dp[row][col-1]%mod);
			}
		}
	}
	return;
}


int main(){
	int H,W;
	cin >> H >> W;
	
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			char c;
			cin >> c; 
			if(c == '.') dp[i][j] = 0;
			else dp[i][j] = -1;
			
		}
	}

	num_paths(H,W);
	long int k = 1e9+7;
	long int count = dp[H-1][W-1] % k;

	cout << count << '\n';
	
	// for(int i=0;i<H;i++){
	// 	for(int j=0;j<W;j++){
	// 		cout << dp[i][j]<<' ';
	// 	}
	// 	cout << '\n';
	// }
	return 0;
}