#include<cstdio>
const static int MAX_N = 100;
bool is_open[MAX_N][5][2];
int P[MAX_N][11];

int main(){
	int N;
	scanf("%d", &N);
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < 5; ++j){
			for (int k = 0; k < 2; ++k){
				int tmp;
				scanf("%d", &tmp);
				is_open[i][j][k] = tmp == 1;
			}
		}
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j <= 10; ++j){
			scanf("%d", &P[i][j]);
		}
	}
	int answer = -1000000000;
	for (unsigned status = 1; status < 1<<10; ++status){
		int profit = 0;
		for (int shop = 0; shop < N; ++shop){
			int competition = 0;
			for (int day = 0; day < 5; ++day){
				for (int time = 0; time < 2; ++time){
					if((status >> day*2 + time & 1) & is_open[shop][day][time]) competition++;
				}
			}
			profit += P[shop][competition];
		}
		if(answer < profit) answer = profit;
	}
	printf("%d\n", answer);
	return 0;
}