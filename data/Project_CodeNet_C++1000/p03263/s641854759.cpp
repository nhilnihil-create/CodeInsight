#include<cstdio>
#include<vector>
using namespace std;
const static int MAX_H = 500;
const static int MAX_W = 500;
bool a[MAX_H][MAX_W];

int main(){
	int H, W;
	scanf("%d %d", &H, &W);
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			int tmp;
			scanf("%d", &tmp);
			a[i][j] = (bool)(tmp & 1);
		}
	}
	vector<int> X_from, Y_from, X_to, Y_to;
	for (int i = 0; i < H-1; ++i){
		for (int j = 0; j < W; ++j){
			if(a[i][j]){
				X_from.push_back(j+1);
				Y_from.push_back(i+1);
				X_to.push_back(j+1);
				Y_to.push_back(i+2);
				a[i+1][j] ^= 1;
			}
		}
	}
	for (int i = 0; i < W-1; ++i){
		if(a[H-1][i]){
			X_from.push_back(i+1);
			Y_from.push_back(H);
			X_to.push_back(i+2);
			Y_to.push_back(H);
			a[H-1][i+1] ^= 1;
		}
	}
	int N = X_from.size();
	printf("%d\n", N);
	for (int i = 0; i < N; ++i){
		printf("%d %d %d %d\n", Y_from[i], X_from[i], Y_to[i], X_to[i]);
	}
	return 0;
}