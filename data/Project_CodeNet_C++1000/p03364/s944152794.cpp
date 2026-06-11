#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int n;
char board[303][303];
int ans;

bool symmetric(){
	for(int i = 1; i <= n; i++){
		for(int j = i + 1; j <= n; j++){
			if(board[i][j] != board[j][i]){
				return false;
			}
		}
	}
	return true;
}

void shift(){
	for(int i = 1; i <= n; i++){
		for(int j = 2; j <= n; j++){
			swap(board[i][j - 1], board[i][j]);
		}
	}
}

int main(){
	scanf("%d", &n);
	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			scanf(" %c", &board[i][j]);
		}
	}
	for(int i = 1; i <= n; i++){
		if(symmetric()){
			ans += n;
		}
		shift();
	}
	printf("%d\n", ans);
	return 0;
}