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
int A[SIZE];

int main(){

	scanf("%d %d",&N,&K);

	int loc;
	for(int i = 0 ; i < N; i++){

		scanf("%d",&A[i]);
		if(A[i] == 1){

			loc = i;
		}
	}

	int ans = BIG_NUM;
	int L,R;

	for(int left = 0; left <= K-1; left++){

		L = loc-left;
		R = loc+((K-1)-left);

		if(L < 0)continue;
		if(R > N-1)continue;

		int tmp = 1;
		//printf("left:%d L:%d R:%d\n",left,L,R);

		if(L > 0){

			tmp += L/(K-1);
			if(L%(K-1) != 0)tmp++;
		}
		if(R < N-1){

			tmp += (N-1-R)/(K-1);
			if((N-1-R)%(K-1) != 0)tmp++;
		}
		ans = min(ans,tmp);
	}

	printf("%d\n",ans);

	return 0;
}
