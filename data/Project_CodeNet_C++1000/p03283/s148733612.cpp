#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <iostream>
#include <string>
using namespace std;

int LR[502][502] = {0};
int dp[502][502] = {0};

void calcdp(){
	for(int i=1; i<=500; i++){
		dp[i][i] = LR[i][i];
	}
	for(int i=1; i<500; i++){
		for(int j=i; j<500; j++){
			int s = 0;
			for(int k=i; k<=j+1; k++){
				s += LR[k][j+1];
			}
			dp[i][j+1] = dp[i][j] + s;
		}
	}
}

int main(int argc, char* argv[]){
	int N, M, Q;
	cin >> N >> M >> Q;
	
	for(int i=1; i<=N; i++){
		for(int j=1; j<=N; j++){ dp[i][j] = -1;}
	}

	for(int i=1; i<=M; i++){
		int l, r;
		cin >> l >> r;
		LR[l][r]++;
	}
	calcdp();
	for(int i=1; i<=Q; i++){
		int p, q;
		cin >> p >> q;
		printf("%d\n",dp[p][q]);
	}
	return 0;
}