#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



#define SIZE 100005

int N,K;
int X[SIZE];

int main(){

	scanf("%d %d",&N,&K);

	int num_plus = 0,num_minus,base_loc=N;

	for(int i = 0; i < N; i++){

		scanf("%d",&X[i]);
		if(X[i] >= 0){
			num_plus++;
			if(base_loc==N){
				base_loc=i;
			}
		}
	}

	if(base_loc == N){

		printf("%d\n",abs(X[N-K]));

	}else if(base_loc == 0){

		printf("%d\n",X[K-1]);

	}else{

		int ans = BIG_NUM;

		int dist_L,dist_R;
		for(int r = K; r >= 0; r--){
			if(base_loc+r-1 >= N)continue;
			int l = K-r;
			if(base_loc-1-l+1 < 0)continue;

			dist_R = X[base_loc+r-1];
			dist_L = abs(X[base_loc-1-l+1]);

			int tmp = 2*min(dist_L,dist_R)+max(dist_L,dist_R);
			ans = min(ans,tmp);
		}

		printf("%d\n",ans);
	}

	return 0;
}
