#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;



int N,K;
int V[105];

int main(){

	scanf("%d %d",&N,&K);

	for(int i = 0; i < N; i++){

		scanf("%d",&V[i]);
	}

	int ans = -BIG_NUM;

	vector<int> work;

	for(int L = 0; L <= min(K,N); L++){ //左から取り出す個数
		for(int R = 0; L+R <= min(K,N); R++){ //右から取り出す個数

			work.clear();

			int sum = 0;

			for(int i = 0; i < L; i++){

				work.push_back(V[i]);
				sum += V[i];
			}

			for(int i = 0; i < R; i++){

				work.push_back(V[(N-1)-i]);
				sum += V[(N-1)-i];
			}

			sort(work.begin(),work.end());

			//捨てられる限り負の石を捨てる
			for(int i = 0; i < min(L+R,K-(L+R)); i++){
				if(work[i] >= 0)break;

				sum -= work[i];
			}
			ans = max(ans,sum);
		}
	}

	printf("%d\n",ans);

	return 0;
}
